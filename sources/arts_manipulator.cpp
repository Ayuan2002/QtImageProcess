//
// Created by Ayuan on 2024/4/24.
//
#include <random>
#include "arts_manipulator.hpp"

ArtsManipulator::~ArtsManipulator() {

}

ArtsManipulator::ArtsManipulator(std::string &file_path) : Manipulator(file_path) {
    try {
        if (this->image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::cvtColor(this->image, this->gray_image,cv::COLOR_BGR2GRAY);
    }catch (cv::Exception &e) {
        std::cout << "Error in ArtsManipulator constructor: " << e.what() << std::endl;
    }catch (std::exception &e) {
        std::cout << "Error in ArtsManipulator constructor: " << e.what() << std::endl;
    }
}

cv::Mat ArtsManipulator::ColorPainting() {
    try{
        cv::Mat watercolor_image;
        cv::stylization(this->image,watercolor_image,3,1.5);
        return watercolor_image;
    }catch (cv::Exception &e) {
        std::cout << "Error in ColorPainting: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat ArtsManipulator::Sketch() {
    try{
        if (this->gray_image.empty()){
            throw std::runtime_error("Image data is empty.");
        }
        // 反色
        cv::Mat negative_image;
        cv::bitwise_not(this->gray_image, negative_image);
        // 高斯模糊
        cv::Mat blurred_image;
        cv::GaussianBlur(negative_image, blurred_image, cv::Size(11, 11), 0.0);
        // 合并颜色
        cv::Mat sketch_image(this->gray_image.size(), CV_8UC1);
        for (int y = 0; y < this->gray_image.rows; y++) {
            const uchar* gray_row = this->gray_image.ptr<uchar>(y);
            const uchar* blurred_row = blurred_image.ptr<uchar>(y);
            uchar* sketch_row = sketch_image.ptr<uchar>(y);
            for (int x = 0; x < this->gray_image.cols; x++) {
                int gray_pixel = gray_row[x];
                int blurred_pixel = blurred_row[x];
                sketch_row[x] = static_cast<uchar>(std::min((gray_pixel * (255 - blurred_pixel) / 255 + blurred_pixel), 255));
            }
        }
        return sketch_image;
    }catch (cv::Exception &e) {
        std::cout << "Error in Sketch: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat ArtsManipulator::OldPhoto() {
    try {
        if (this->image.empty()){
            throw std::runtime_error("Image data is empty.");
        }
        if (this->image.channels()==1)
            return this->image.clone();
        cv::Mat old_photo_image(this->image.size(), this->image.type());
        for (int i = 0; i < this->image.rows; ++i) {
            for (int j = 0; j < this->image.cols; ++j) {
                cv::Vec3b pixel=this->image.at<cv::Vec3b>(i,j);
                cv::Vec3b new_pixel;
                float R=pixel[2]*0.393+pixel[1]*0.769+pixel[0]*0.189;
                float G=pixel[2]*0.349+pixel[1]*0.686+pixel[0]*0.168;
                float B=pixel[2]*0.272+pixel[1]*0.534+pixel[0]*0.131;
                new_pixel[0] = cv::saturate_cast<uchar>(B);
                new_pixel[1] = cv::saturate_cast<uchar>(G);
                new_pixel[2] = cv::saturate_cast<uchar>(R);
                old_photo_image.at<cv::Vec3b>(i,j)=new_pixel;
            }
        }
        return old_photo_image;
    }catch (cv::Exception &e) {
        std::cout << "Error in OldPhoto: " << e.what() << std::endl;
    }
    return {};
}

ArtsManipulator::ArtsManipulator() = default;

