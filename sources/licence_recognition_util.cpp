//
// Created by Ayuan on 2024/4/23.
//
#include <licence_recognition_util.hpp>
LicenceRecognition::~LicenceRecognition() {
    cv::destroyAllWindows();
    character_images.clear();
    province_images.clear();
    template_images.clear();
    alphabet_images.clear();
};

LicenceRecognition::LicenceRecognition() = default;

LicenceRecognition::LicenceRecognition(std::string &path) {
    try {
        this->image= cv::imread(path,cv::IMREAD_UNCHANGED);
        this->gray_image = cv::Mat::zeros(image.size(), CV_8UC1);
    }catch (cv::Exception& e){
        std::cerr << e.what() << std::endl;
    }
}
void LicenceRecognition::preprocessImage() {
    // 转换为灰度图像
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    // 高斯滤波
    cv::GaussianBlur(gray_image, gaussian_blur_image, cv::Size(5, 5), 0);

    // Sobel边缘检测
    cv::Mat grad_x, grad_y, abs_grad_x, abs_grad_y;
    cv::Sobel(gaussian_blur_image, grad_x, CV_16S, 1, 0, 3);
    cv::convertScaleAbs(grad_x, abs_grad_x);
    cv::Sobel(gaussian_blur_image, grad_y, CV_16S, 0, 1, 3);
    cv::convertScaleAbs(grad_y, abs_grad_y);
    cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, sobel_image);

    // 二值化
    cv::threshold(sobel_image, binary_image, 120,255,  cv::THRESH_BINARY);
    //cv::imshow("Binary Image", binary_image);
    // 形态学操作：闭运算
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(20, 5));
    cv::morphologyEx(binary_image, close_image, cv::MORPH_CLOSE, element);
    // 形态学操作：去除小区域
    cv::Mat ele = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    cv::erode(close_image, close_image, ele);
    ele = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(30, 10));
    cv::dilate(close_image, close_image, ele);
    // 显示处理后的图像
    //cv::imshow("Preprocessed Image", close_image);
}
void LicenceRecognition::extractPlateRegion() {
    // 克隆原图像
    marked_image = image.clone();
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(close_image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    // 轮廓筛选条件
    cv::Rect best_plate;
    float idealAspectRatio = 3.14; // 假设理想的宽高比为3.14
    float aspectRatioRange = 1; // 允许的宽高比偏差范围
    int maxArea=0;
    for (const auto & contour : contours) {
        cv::Rect bounding_rect = cv::boundingRect(contour);
        float aspect_ratio = (float)bounding_rect.width / bounding_rect.height;
        // 检查轮廓是否在面积和长宽比的预期范围内
        if (bounding_rect.area() < 2000 || bounding_rect.area() > 100000 ||
            aspect_ratio < (idealAspectRatio - aspectRatioRange) ||
            aspect_ratio > (idealAspectRatio + aspectRatioRange)) {
            continue;
        }
        if (bounding_rect.area()>maxArea){
            maxArea=bounding_rect.area();
            best_plate = bounding_rect;
        }
        cv::rectangle(marked_image, bounding_rect, cv::Scalar(255, 0, 0), 2);
    }
    // 标记找到最佳的车牌轮廓

    cv::rectangle(marked_image, best_plate, cv::Scalar(0, 0, 255), 2);
    best_rect=best_plate;
    //cv::imshow("marked_image", marked_image);
}

int LicenceRecognition::recognizePlate() {
    try {
        preprocessImage();
        extractPlateRegion();
        extractCharacterRegion();
        loadTemplates();
        std::string s, alpha;
        recognizeProvince(s);
        plate += province_map.at(s);
        recognizeAlphabet(alpha);
        plate += alpha;
        for (int i = 2; i < character_images.size(); ++i) {
            std::string str;
            cv::Mat character_image = character_images[i];
            recognizeCharacters(character_image, str);
            plate += str;
        }
        printResult();
    }catch (cv::Exception& e){
        std::cerr <<"recognizePlate error:"<< e.what() << std::endl;
        return -1;
    }catch (std::exception& e){
        std::cerr <<"recognizePlate error:"<< e.what() << std::endl;
        return -1;
    }
    return 0;
}

void LicenceRecognition::extractCharacterRegion() {
    //在原图中裁剪出前面已经找到的车牌区域
    plate_image=image(best_rect).clone();
    cv::cvtColor(plate_image, plate_image, cv::COLOR_BGR2GRAY);
    cv::Mat binary_plate_image;
    cv::threshold(plate_image, binary_plate_image, 130,255,  cv::THRESH_BINARY);

    cv::Mat Kernel=cv::getStructuringElement(cv::MORPH_RECT,cv::Size(2,2));
    cv::dilate(binary_plate_image,binary_plate_image,Kernel);

    // 查找轮廓提取车牌字符
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary_plate_image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    const float minAspectRatio = 0.05; // 最小宽高比
    const float maxAspectRatio = 1.0; // 最大宽高比
    const int maxArea = 3000;
    const int minArea = 200;
    // 对轮廓按照左端点从小到大排序
    std::sort(contours.begin(), contours.end(), [](const std::vector<cv::Point>& a, const std::vector<cv::Point>& b) {
        return cv::boundingRect(a).x < cv::boundingRect(b).x;
    });
    // 遍历所有轮廓
    for (const auto &contour : contours) {
        // 可以添加轮廓过滤条件，例如根据轮廓面积、宽高比等进行过滤
        // 计算轮廓的外接矩形
        cv::Rect boundingRect = cv::boundingRect(contour);
        float aspectRatio = (float)boundingRect.width / boundingRect.height;
        int area = boundingRect.area();

        // 根据轮廓面积和宽高比进行过滤
        if (aspectRatio >= minAspectRatio && aspectRatio <= maxAspectRatio &&
            area >= minArea && area <= maxArea) {
            cv::rectangle(plate_image, boundingRect, cv::Scalar(0, 0, 255), 2);
            // 填充到字符容器
            character_images.push_back(plate_image(boundingRect));
        }
    }
    if (character_images.size()<7){
        throw std::runtime_error("can not recognize plate characters,didn't find enough characters");
    }else if(character_images.size()<2){
        throw std::runtime_error("can not recognize plate characters");
    }else if (character_images.size()>7){
        while(character_images.size()>7){
            int maxHeight = 0;
            for (const auto& img : character_images) {
                if (img.rows > maxHeight) {
                    maxHeight = img.rows;
                }
            }
            // 在找到的最大高度中查找第一个匹配的字符并删除
            auto iter = std::find_if(character_images.begin(), character_images.end(),
                                     [maxHeight](const cv::Mat& img) { return img.rows == maxHeight; });
            if (iter != character_images.end()) {
                character_images.erase(iter); // 删除找到的字符
            }
        }
    }
    //cv::imshow("plate_image", plate_image);
    //再对字符容器中的图片进行阈值处理
    for (auto &img : character_images) {
        cv::threshold(img, img, 130, 255, cv::THRESH_BINARY);
        cv::resize(img, img, cv::Size(12, 20), cv::INTER_LINEAR);
    }

}

void LicenceRecognition::loadTemplates() {
    // 加载数字图像
    for (int i = 0; i < 10; ++i) {
        std::string filename = nums_path + "num_" + std::to_string(i) + ".png";
        cv::Mat img = cv::imread(filename, cv::IMREAD_GRAYSCALE);
        if (!img.empty()) {
            cv::resize(img, img, cv::Size(12, 20), cv::INTER_LINEAR);
            template_images[std::to_string(i)] = img;
        }
    }
    // 加载字母图像
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::string filename = alphabet_path + "alpha_" + std::string(1, c) + ".png";
        cv::Mat img = cv::imread(filename, cv::IMREAD_GRAYSCALE);
        if (!img.empty()) {
            cv::resize(img, img, cv::Size(12, 20), cv::INTER_LINEAR);
            template_images[std::string(1,c)] = img;
            alphabet_images[std::string(1,c)] = img;
        }
    }
    // 加载省份图像
    for (const auto& p : all_provinces) {
        std::string filename = province_path + "province_" + p + ".png";
        cv::Mat img = cv::imread(filename, cv::IMREAD_GRAYSCALE);
        if (!img.empty()) {
            cv::resize(img, img, cv::Size(12, 20), cv::INTER_LINEAR);
            province_images[p] = img;
        }
    }
}

void LicenceRecognition::recognizeProvince(std::string &input) {
    // 获取第一个字符图片
    cv::Mat first_char_image = character_images[0];

    // 遍历省份模板列表，进行模板匹配
    double max_corr = -1; // 最大相关性
    std::string matched_province; // 匹配的省份
    for (const auto& province_img : province_images) {
        // 进行模板匹配
        cv::Mat result;
        cv::matchTemplate(first_char_image, province_img.second, result, cv::TM_CCOEFF_NORMED);
        // 找到最大相关性
        double minVal, maxVal;
        cv::Point minLoc, maxLoc;
        cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
        // 更新最大相关性和匹配的省份
        if (maxVal > max_corr) {
            max_corr = maxVal;
            matched_province = province_img.first;
        }
    }
    input = matched_province;
    //清除所有的省份模板节省内存
    province_images.clear();
}

void LicenceRecognition::recognizeAlphabet(std::string &input) {
    // 获取第二个字符图片
    cv::Mat second_char_image = character_images[1];
    // 遍历字母模板列表，进行模板匹配
    double max_corr = -1; // 最大相关性
    std::string matched_alphabet; // 匹配的字母
    for (const auto& alphabet_img : alphabet_images) {
        // 进行模板匹配
        cv::Mat result;
        cv::matchTemplate(second_char_image, alphabet_img.second, result, cv::TM_CCORR_NORMED);
        // 找到最大相关性
        double minVal, maxVal;
        cv::Point minLoc, maxLoc;
        cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
        // 更新最大相关性和匹配的字母
        if (maxVal > max_corr) {
            max_corr = maxVal;
            matched_alphabet = alphabet_img.first;
        }
    }
    input = matched_alphabet;
    //清除所有的字母模板节省内存
    alphabet_images.clear();
}

void LicenceRecognition::recognizeCharacters(cv::Mat& input, std::string &output) {
    double max_corr = -1;
    std::string matched_char;
    for (const auto& template_img : template_images) {
        // 进行模板匹配
        cv::Mat result;
        cv::matchTemplate(input, template_img.second, result, cv::TM_CCOEFF_NORMED);
        // 找到最大相关性
        double minVal, maxVal;
        cv::Point minLoc, maxLoc;
        cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
        // 更新最大相关性和匹配的字符
        if (maxVal > max_corr) {
            max_corr = maxVal;
            matched_char = template_img.first;
        }
    }
    output=matched_char;
}

void LicenceRecognition::recognizeCharactersByFeature(cv::Mat &input, std::string &output) {
    // 创建ORB特征检测器和描述符提取器
    cv::Ptr<cv::SIFT> detector = cv::SIFT::create();

    // 提取输入图像的特征点和描述符
    std::vector<cv::KeyPoint> keypoints_input;
    cv::Mat descriptors_input;
    detector->detectAndCompute(input, cv::noArray(), keypoints_input, descriptors_input);

    double max_score = 0.0;
    std::string matched_char;

    // 遍历所有模板图像
    for (const auto& template_img : template_images) {
        // 提取模板图像的特征点和描述符
        std::vector<cv::KeyPoint> keypoints_template;
        cv::Mat descriptors_template;
        detector->detectAndCompute(template_img.second, cv::noArray(), keypoints_template, descriptors_template);

        // 使用FLANN匹配器进行特征点匹配
        cv::FlannBasedMatcher matcher;
        std::vector<std::vector<cv::DMatch>> knn_matches;
        matcher.knnMatch(descriptors_template, descriptors_input, knn_matches, 2);

        // 计算匹配度分数
        double score = 0.0;
        for (size_t i = 0; i < knn_matches.size(); ++i) {
            if (knn_matches[i][0].distance < 0.8 * knn_matches[i][1].distance) {
                score += 1.0;
            }
        }

        // 更新最大匹配度分数和匹配字符
        if (score > max_score) {
            max_score = score;
            matched_char = template_img.first;
        }
    }
    // 将匹配度最高的字符作为结果输出
    output = matched_char;
}

void LicenceRecognition::printResult() {
    std::cout<<"result"<<plate<<std::endl;
}

const cv::Mat &LicenceRecognition::getGrayImage() const {
    return gray_image;
}

const cv::Mat &LicenceRecognition::getGaussianBlurImage() const {
    return gaussian_blur_image;
}

const cv::Mat &LicenceRecognition::getSobelImage() const {
    return sobel_image;
}

const cv::Mat &LicenceRecognition::getBinaryImage() const {
    return binary_image;
}

const cv::Mat &LicenceRecognition::getCloseImage() const {
    return close_image;
}

const cv::Mat &LicenceRecognition::getMarkedImage() const {
    return marked_image;
}

const cv::Mat &LicenceRecognition::getPlateImage() const {
    return plate_image;
}

const std::string &LicenceRecognition::getPlate() const {
    return plate;
}