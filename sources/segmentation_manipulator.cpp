//
// Created by Ayuan on 2024/4/9.
//
#include "segmentation_manipulator.hpp"
SegmentationManipulator::SegmentationManipulator() = default;

SegmentationManipulator::SegmentationManipulator(std::string &image_path) : Manipulator(image_path) {
    try {
        if (this->image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::cvtColor(this->image, this->gray_image, cv::COLOR_BGR2GRAY);
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred: " << e.what() << std::endl;
        throw;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        throw;
    }
}

cv::Mat SegmentationManipulator::detect_edges(int low_threshold, int high_threshold) {
    try {
        if (this->image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat edges;
        cv::Canny(this->gray_image, edges, low_threshold, high_threshold);
        return edges;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred: " << e.what() << std::endl;
        return {};
    }
}

cv::Mat SegmentationManipulator::detect_lines(int low_threshold, int high_threshold) {
    try {
            if (this->gray_image.empty()) {
                throw std::runtime_error("Image data is empty.");
            }
        cv::Mat edges = this->detect_edges(low_threshold, high_threshold);
        std::vector<cv::Vec2f> detected_lines;
        cv::HoughLines(edges, detected_lines, 1, CV_PI / 180, 100);
        // 绘制检测到的直线
        cv::Mat lines_image = this->image.clone(); // 创建原始图像的副本
        for (auto & detected_line : detected_lines) {
            float rho = detected_line[0];
            float theta = detected_line[1];
            cv::Point pt1, pt2;
            double a = std::cos(theta), b = std::sin(theta);
            double x0 = a * rho, y0 = b * rho;
            pt1.x = cvRound(x0 + 1000 * (-b));
            pt1.y = cvRound(y0 + 1000 * (a));
            pt2.x = cvRound(x0 - 1000 * (-b));
            pt2.y = cvRound(y0 - 1000 * (a));
            cv::line(lines_image, pt1, pt2, cv::Scalar (0, 0, 255),5, cv::LINE_AA,0);
        }
        return lines_image;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat SegmentationManipulator::apply_threshold(int threshold_value) {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat threshold_image;
        cv::threshold(this->gray_image, threshold_image, threshold_value, 255, cv::THRESH_BINARY);
        return threshold_image;
    }catch (const cv::Exception& e){
        std::cerr<<e.what()<<std::endl;
    }
    return {};
}


