//
// Created by Ayuan on 2024/4/23.
//

#ifndef QTIMAGEPROCESS_LICENCE_RECOGNITION_UTIL_HPP
#define QTIMAGEPROCESS_LICENCE_RECOGNITION_UTIL_HPP
#include <opencv2/opencv.hpp>
static const std::string nums_path="../pictures/nums/";
static const std::string alphabet_path="../pictures/alphabet/";
static const std::string province_path="../pictures/province/";
static const std::vector<std::string> all_provinces={"anhui", "beijing", "chongqing", "fujian", "gansu", "guangdong", "guangxi",
                                                     "guizhou", "hainan", "hebei", "heilongjiang", "henan", "hubei", "hunan",
                                                     "jiangsu", "jiangxi", "jilin", "liaoning", "neimenggu", "ningxia", "qinghai",
                                                     "shandong", "shanghai", "shanxi", "shaanxi","sichuan", "tianjin", "xinjiang", "xizang",
                                                     "yunnan", "zhejiang"};
static const std::map<std::string, std::string> province_map = {
        {"anhui", "皖"}, {"beijing", "京"}, {"chongqing", "渝"}, {"fujian", "闽"}, {"gansu", "甘"},
        {"guangdong", "粤"}, {"guangxi", "桂"}, {"guizhou", "贵"}, {"hainan", "琼"}, {"hebei", "冀"},
        {"heilongjiang", "黑"}, {"henan", "豫"}, {"hubei", "鄂"}, {"hunan", "湘"}, {"jiangsu", "苏"},
        {"jiangxi", "赣"}, {"jilin", "吉"}, {"liaoning", "辽"}, {"neimenggu", "蒙"}, {"ningxia", "宁"},
        {"qinghai", "青"}, {"shandong", "鲁"}, {"shanghai", "沪"}, {"shanxi", "晋"},{"shaanxi","陕"}, {"sichuan", "川"},
        {"tianjin", "津"}, {"xinjiang", "新"}, {"xizang", "藏"}, {"yunnan", "滇"}, {"zhejiang", "浙"}
};
class LicenceRecognition {
private:
    cv::Mat image;//原始图像
    cv::Mat gray_image;
    cv::Mat gaussian_blur_image;//高斯滤波后的图像
    cv::Mat sobel_image;//sobel边缘检测后的图像
    cv::Mat binary_image;//二值化后的图像
    cv::Mat close_image;//闭运算后图像
    cv::Mat marked_image;//标记
    cv::Mat plate_image;//车牌区域
    std::string plate;
    cv::Rect best_rect;
    std::vector<cv::Mat> character_images;//来自图片的车牌字符图像
    std::map<std::string, cv::Mat>template_images;//除省份外所有字符模板图像
    std::map<std::string, cv::Mat>alphabet_images;//所有英文字符模板图像
    std::map<std::string, cv::Mat> province_images;//所有省份模板图像
public:
    LicenceRecognition();
    explicit LicenceRecognition(std::string &path);
    ~LicenceRecognition();
    // 加载字符模板图像
    void loadTemplates();
    // 预处理图像
    void preprocessImage();
    // 提取车牌区域
    void extractPlateRegion();
    // 提取字符区域
    void extractCharacterRegion();
    // 字符识别
    void recognizeCharacters(cv::Mat& input, std::string & output);
    // 完整的车牌识别流程
    int recognizePlate();
    // 打印识别结果
    void printResult();
    //识别第一个省份字符
    void recognizeProvince(std::string & input);
    //识别第二个英文字符
    void recognizeAlphabet(std::string & input);
    //字符识别-特征识别器
    void recognizeCharactersByFeature(cv::Mat& input, std::string & output);
    //get
    const cv::Mat &getGrayImage() const;
    const cv::Mat &getGaussianBlurImage() const;
    const cv::Mat &getSobelImage() const;
    const cv::Mat &getBinaryImage() const;
    const cv::Mat &getCloseImage() const;
    const cv::Mat &getMarkedImage() const;
    const cv::Mat &getPlateImage() const;
    const std::string &getPlate() const;

};
#endif //QTIMAGEPROCESS_LICENCE_RECOGNITION_UTIL_HPP
