//
// Created by Ayuan on 2024/3/4.
//
#include "based.hpp"
#include "globe_define_words.h"

//根据输入的角度旋转图像，仿射变换
cv::Mat ImageBasedManipulator::rotate(int angle) {
    if (angle == 0 || angle == 360) {
        return this->image.clone();
    }
    if (this->image.empty()) {
        return {};
    }
    // 计算旋转矩阵
    cv::Point2f center(this->image.cols / 2.0f, this->image.rows / 2.0f);
    cv::Mat rotMat = cv::getRotationMatrix2D(center, angle, 1.0);
    // 计算图像的新边界
    double abs_cos = std::abs(rotMat.at<double>(0, 0));
    double abs_sin = std::abs(rotMat.at<double>(0, 1));
    // 计算新图像的宽度和高度
    int boundW = static_cast<int>(this->image.rows * abs_sin + this->image.cols * abs_cos);
    int boundH = static_cast<int>(this->image.rows * abs_cos + this->image.cols * abs_sin);
    // 调整旋转矩阵以考虑平移
    rotMat.at<double>(0, 2) += boundW / 2 - center.x;
    rotMat.at<double>(1, 2) += boundH / 2 - center.y;
    // 执行仿射变换
    cv::Mat rotatedImage;
    cv::warpAffine(this->image, rotatedImage, rotMat, cv::Size(boundW, boundH), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255, 0));
    return rotatedImage;
}



void ImageBasedManipulator::display() {
    cv::imshow("n",this->image);
}

ImageBasedManipulator::~ImageBasedManipulator() = default;
//实现水平翻转
cv::Mat ImageBasedManipulator::flip_horizontal() {
    try {
        if (this->image.empty()) {
            return {};
        }
        cv::Mat result(this->image.rows, this->image.cols, this->image.type());
        // 遍历像素并且翻转位置赋值
        for (int i = 0; i < this->image.rows; ++i) {
            for (int j = 0; j < this->image.cols; ++j) {
                // 如果是单通道图像
                if (this->image.channels() == 1) {
                    result.at<uchar>(i, j) = this->image.at<uchar>(i, this->image.cols - j - 1);
                }
                    // 如果是三通道图像
                else if (this->image.channels() == 3) {
                    result.at<cv::Vec3b>(i, j) = this->image.at<cv::Vec3b>(i, this->image.cols - j - 1);
                }
                    // 如果是四通道图像
                else if (this->image.channels() == 4) {
                    result.at<cv::Vec4b>(i, j) = this->image.at<cv::Vec4b>(i, this->image.cols - j - 1);
                }
            }
        }
        return result;
    } catch (const cv::Exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }
    return {};
}

//实现垂直翻转
cv::Mat ImageBasedManipulator::flip_vertical() {
    if (this->image.empty()) {
        return {};
    }
    cv::Mat result;
    cv::flip(this->image, result, 0);
    return result;
}
//实现缩放
cv::Mat ImageBasedManipulator::resize(double scale_percent) {
    if (this->image.empty()) {
        return {};
    }
    int new_width = static_cast<int>(this->image.cols * scale_percent / 100);
    int new_height = static_cast<int>(this->image.rows * scale_percent / 100);
    // 创建缩放后的图像
    cv::Mat result;
    cv::resize(this->image, result, cv::Size(new_width, new_height), 0, 0, cv::INTER_LINEAR);
    return result;
}
//实现灰度化
cv::Mat ImageBasedManipulator::gray() {
    if (this->image.empty()) {
        return {};
    }
    cv::Mat result(this->image.rows, this->image.cols, CV_8UC1); // 创建一个单通道的灰度图像
    for (int i = 0; i < this->image.rows; ++i) {
        for (int j = 0; j < this->image.cols; ++j) {
            cv::Vec4b pixel = this->image.at<cv::Vec4b>(i, j);
            int gray_value = static_cast<int>(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);
            result.at<uchar>(i, j) = gray_value;
        }
    }
    return result;
}



