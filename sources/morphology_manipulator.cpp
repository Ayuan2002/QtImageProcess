//
// Created by Ayuan on 2024/4/16.
//
#include <morphology_manipulator.hpp>


MorphologyManipulator::MorphologyManipulator() = default;

MorphologyManipulator::MorphologyManipulator(std::string &image_path) : Manipulator(image_path) {
    try {
        if (this->image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::cvtColor(this->image, this->gray_image, cv::COLOR_BGR2GRAY);
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
        throw;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred in constructor: " << e.what() << std::endl;
        throw;
    }
}

cv::Mat MorphologyManipulator::dilation(int radius) {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }

        cv::Mat result = cv::Mat::zeros(this->gray_image.size(), this->gray_image.type());

        int dilation_size = 2 * radius + 1;
        cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilation_size, dilation_size),
                                                    cv::Point(radius, radius));
        cv::dilate(this->gray_image, result, element);

        return result;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in dilation: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat MorphologyManipulator::erosion(int radius) {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat result = cv::Mat::ones(this->gray_image.size(), this->gray_image.type()) * 255;

        int erosion_size = 2 * radius + 1;
        cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(erosion_size, erosion_size),
                                                    cv::Point(radius, radius));
        cv::erode(this->gray_image, result, element);
        return result;
    }catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in erosion: " << std::endl;
    }
    return {};
}

cv::Mat MorphologyManipulator::opening(int radius) {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat result;
        cv::Mat src= erosion(radius, this->gray_image);
        result = dilation(radius, src);
        return result;
    }catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in opening: " << std::endl;
    }
    return {};
}

cv::Mat MorphologyManipulator::erosion(int radius, cv::Mat &input) {
    try {
        if (input.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat result = cv::Mat::ones(input.size(), input.type()) * 255;

        int erosion_size = 2 * radius + 1;
        cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(erosion_size, erosion_size),
                                                    cv::Point(radius, radius));
        cv::erode(input, result, element);
        return result;
    }catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in erosion: " << std::endl;
    }
    return {};
}

cv::Mat MorphologyManipulator::dilation(int radius, cv::Mat &input) {
    try {
        if (input.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat result = cv::Mat::zeros(input.size(), input.type());

        int dilation_size = 2 * radius + 1;
        cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilation_size, dilation_size),cv::Point (radius, radius));
        cv::dilate(input, result, element);
        return result;
    }catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in dilation: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat MorphologyManipulator::closing(int radius) {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat result;
        cv::Mat src= dilation(radius, this->gray_image);
        result = erosion(radius, src);
        return result;
    }catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in closing: " << std::endl;
    }
    return {};
}

MorphologyManipulator::~MorphologyManipulator() = default;
