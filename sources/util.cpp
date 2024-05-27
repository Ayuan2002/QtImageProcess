//
// Created by Ayuan on 2024/4/9.
//
#include <util.hpp>
#include <opencv2/imgproc.hpp>
#include <globe_define_words.h>
#include <QDateTime>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/flann/random.h>
#include <random>

QPixmap HistogramUtil::calculateGrayscaleHistogram(const QImage &image) {
    QVector<int> histogram(256, 0); // 存储每个灰度级别的像素数量
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            QColor color(image.pixel(i, j));
            int gray = qGray(color.rgb()); // 获取灰度级别
            if ((gray >= 30) && (gray <= 225)) {
                histogram[gray]++;
            }
        }
    }
    QImage histogramImage(256, 256, QImage::Format_RGB32); // 创建直方图图像
    histogramImage.fill(Qt::black); // 设置背景颜色
    QPainter painter(&histogramImage);
    painter.setPen(Qt::white);
    int maxCount = *std::max_element(histogram.begin(), histogram.end()); // 获取像素数量最大值
    for (int i = 0; i < 256; i++) {
        int count = histogram[i];
        int x = i;
        int y = histogramImage.height() - (static_cast<double>(count) / maxCount) * histogramImage.height();
        painter.drawLine(x, histogramImage.height(), x, y);
    }
    //调整大小
    return QPixmap::fromImage(histogramImage).scaled(400, 400, Qt::KeepAspectRatio);
}

QPixmap ImageUtil::convertToQPixmap(const cv::Mat &mat) {
    // 将BGR格式转换为RGB格式
    cv::Mat rgbMat;
    QImage image;
    if (mat.channels() == 4){
        cv::cvtColor(mat, rgbMat, cv::COLOR_BGR2BGRA);
        image = QImage(rgbMat.data, rgbMat.cols, rgbMat.rows, static_cast<int>(rgbMat.step), QImage::Format_ARGB32);
    }
    else if (mat.channels() == 3){
        cv::cvtColor(mat, rgbMat, cv::COLOR_BGR2RGB);
        image = QImage(rgbMat.data, rgbMat.cols, rgbMat.rows, static_cast<int>(rgbMat.step), QImage::Format_RGB888);
    }
    else {
        cv::cvtColor(mat, rgbMat, cv::COLOR_GRAY2RGB);
        image = QImage(rgbMat.data, rgbMat.cols, rgbMat.rows, static_cast<int>(rgbMat.step), QImage::Format_RGB888);
    }
    return QPixmap::fromImage(image);
}

QPixmap ImageUtil::convertToQPixmap(const cv::Mat &image, int) {
    QPixmap pixmap;
    try {
        cv::Mat mat = image.clone();
        QDateTime currentDateTime = QDateTime::currentDateTime();
        std::string file_name = cache_file_path + currentDateTime.toString("yyyyMMddhhmm").toStdString() + ".png";
        cv::imwrite(file_name, mat);
        pixmap = QPixmap(QString::fromStdString(file_name));
    }catch (const cv::Exception& e){
        std::cerr << "Error in Util class: " << e.what() << std::endl;
    }
    return pixmap;
}

QPixmap ImageUtil::addSaltNoise(const QString &input) {
    try {
        cv::Mat image = cv::imread(input.toStdString(),cv::IMREAD_UNCHANGED);
        if (image.empty()){
            return {};
        }
        auto channels = image.channels();
        if (channels == 1) {
            // 灰度图像处理方式
            addSaltNoiseGray(image);
        } else if (channels == 3) {
            // 彩色图像处理方式
            addSaltNoiseColor(image);
        } else if (channels == 4) {
            // 带透明通道的图像处理方式
            addSaltNoiseWithAlpha(image);
        }
        return convertToQPixmap(image);
    }catch (const cv::Exception& e){
        std::cerr << "Error in Util class_add salt noise: " << e.what() << std::endl;
    }
    return {};
}
void ImageUtil::addSaltNoiseGray(cv::Mat &image) {
    // 获取图像宽高
    int rows = image.rows;
    int cols = image.cols;

    // 设置椒盐噪声比例
    double noise_ratio = 0.02;

    // 计算要添加的椒盐噪声点的数量
    int noise_pixels = static_cast<int>(rows * cols * noise_ratio);

    // 在随机位置添加椒盐噪声
    for (int i = 0; i < noise_pixels; ++i) {
        int x = cvflann::rand_int() % cols;
        int y = cvflann::rand_int() % rows;
        if (cvflann::rand_int() % 2 == 0) {
            // 添加椒噪声
            image.at<uchar>(y, x) = 0;
        } else {
            // 添加盐噪声
            image.at<uchar>(y, x) = 255;
        }
    }
}

void ImageUtil::addSaltNoiseColor(cv::Mat &image) {
    int rows = image.rows;
    int cols = image.cols;
    // 设置椒盐噪声比例
    double noise_ratio = 0.02;
    // 计算要添加的椒盐噪声点的数量
    int noise_pixels = static_cast<int>(rows * cols * noise_ratio);
    // 在随机位置添加椒盐噪声
    for (int i = 0; i < noise_pixels; ++i) {
        int x = cvflann::rand_int() % cols;
        int y = cvflann::rand_int() % rows;
        if (cvflann::rand_int() % 2 == 0) {
            // 添加椒噪声
            image.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0); // 黑色
        } else {
            // 添加盐噪声
            image.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255); // 白色
        }
    }
}

void ImageUtil::addSaltNoiseWithAlpha(cv::Mat &image) {
    int rows = image.rows;
    int cols = image.cols;
    // 设置椒盐噪声比例
    double noise_ratio = 0.02;
    // 计算要添加的椒盐噪声点的数量
    int noise_pixels = static_cast<int>(rows * cols * noise_ratio);
    for (int i = 0; i < noise_pixels; ++i) {
        int x = cvflann::rand_int() % cols;
        int y = cvflann::rand_int() % rows;
        if (cvflann::rand_int() % 2 == 0) {
            // 添加椒噪声
            image.at<cv::Vec4b>(y, x) = cv::Vec4b(0, 0, 0, 255); // 黑色
        } else {
            // 添加盐噪声
            image.at<cv::Vec4b>(y, x) = cv::Vec4b(255, 255, 255, 255);// 白色
        }
    }
}

QPixmap ImageUtil::addGaussianNoise(const QString &input) {
    try {
        cv::Mat image = cv::imread(input.toStdString(), cv::IMREAD_UNCHANGED);
        if (image.empty()) {
            return {};
        }
        // 设置高斯噪声的参数
        double mean = 0.0;  // 均值
        double stddev = 20.0;  // 标准差
        // 生成高斯噪声并叠加到图像上
        cv::Mat noise;
        noise=cv::Mat(image.size(), image.type());
        cv::randn(noise, cv::Scalar(mean), cv::Scalar(stddev));
        cv::add(image, noise, image);
        return convertToQPixmap(image);
    }catch (const cv::Exception& e){
        std::cerr << "Error in Util class_add gaussian noise: " << e.what() << std::endl;
    }
    return {};
}

QPixmap ImageUtil::addSpeckleNoise(const QString &input) {
    try{
        cv::Mat image= cv::imread(input.toStdString(), cv::IMREAD_UNCHANGED);
        if (image.empty()){
            return {};
        }
        // 计算图像的均值
        cv::Scalar mean, stddev;
        cv::meanStdDev(image, mean, stddev);
        // 生成斑点噪声矩阵
        cv::Mat noise(image.size(), image.type());
        cv::randn(noise, cv::Scalar::all(0), cv::Scalar::all(stddev.val[0]));
        // 将斑点噪声添加到原始图像中
        cv::Mat noisyImage = image + noise;
        // 转换为 QPixmap 并返回
        return convertToQPixmap(noisyImage);
    }catch (const cv::Exception& e){
        std::cerr << "Error in Util class_add speckle noise: ";
    }
    return {};
}

QPixmap ImageUtil::addSimulationNoise(const QString &input) {
    try {
        cv::Mat image= cv::imread(input.toStdString(), cv::IMREAD_UNCHANGED);
        if (image.empty()){
            return {};
        }
        std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        double noise_mean = 0.0;
        double noise_stddev = 10.0;
        auto channels = image.channels();
        for (int i = 0; i < image.cols; ++i) {
            for (int j = 0; j < image.rows; ++j) {
                if (channels == 1){
                    double noise_value = noise_mean + noise_stddev * dist(rng) / (RAND_MAX + 1.0);
                    image.at<uchar>(i, j) += noise_value;
                }
                else if(channels == 3){
                    // 使用高斯分布生成噪声值
                    double noise_value = noise_mean + noise_stddev * dist(rng) / (RAND_MAX + 1.0);
                    // 添加噪声到每个通道
                    for (int c = 0; c < 3; ++c) {
                        image.at<cv::Vec3b>(i, j)[c] += noise_value;
                    }
                }
                else if(channels == 4){
                    // 使用高斯分布生成噪声值
                    double noise_value = noise_mean + noise_stddev * dist(rng) / (RAND_MAX + 1.0);
                    // 添加噪声到每个通道
                    for (int c = 0; c < 4; ++c) {
                        image.at<cv::Vec4b>(i, j)[c] += noise_value;
                    }
                }
            }
        }
        return convertToQPixmap(image);
    }catch (const cv::Exception& e){
        std::cerr << "Error in Util class_add simulation noise: ";
    }
    return {};
}

QPixmap ImageUtil::getPixmapFromFile(const QString &filePath) {
    try {
        cv::Mat image = cv::imread(filePath.toStdString(), cv::IMREAD_UNCHANGED);
        if (image.empty()){
            return {};
        }
        return convertToQPixmap(image);
    }catch (const cv::Exception& e){
        std::cerr << "Error in Util class_get pixmap from file: "<<e.what();
    }
    return {};
}

