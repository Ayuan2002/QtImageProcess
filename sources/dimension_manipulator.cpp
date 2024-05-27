//
// Created by Ayuan on 2024/4/15.
//
#include <dimension_manipulator.hpp>

DimensionManipulator::DimensionManipulator() = default;

DimensionManipulator::DimensionManipulator(std::string &image_path) : Manipulator(image_path) {
    try {
        if (this->image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::cvtColor(this->image, this->gray_image, cv::COLOR_BGR2GRAY);
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
        throw;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        throw;
    }
}
//可能导致越界内存访问
cv::Mat DimensionManipulator::histogram_equalization() {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat equalized_image;
        cv::Mat hist;
        int hist_size = 256;
        float range[] = {0, 256};
        const float* hist_range = {range};
        cv::calcHist(&this->gray_image, 1, 0, cv::Mat(), hist, 1, &hist_size, &hist_range, true, false);
        cv::Mat cdf;
        hist.copyTo(cdf);
        for (int i = 1; i < hist_size; ++i) {
            cdf.at<float>(i) += cdf.at<float>(i - 1);
        }
        cdf /= this->gray_image.total();
        // 创建均衡化后的图像
        equalized_image = cv::Mat(this->gray_image.size(), this->gray_image.type());
        for (int i = 0; i < this->gray_image.rows; ++i) {
            for (int j = 0; j < this->gray_image.cols; ++j) {
                // 检查索引范围
                if (i >= 0 && i < this->gray_image.rows && j >= 0 && j < this->gray_image.cols) {
                    equalized_image.at<uchar>(i, j) = cv::saturate_cast<uchar>(cdf.at<float>(this->gray_image.at<uchar>(i, j)) * 255);
                } else {
                    std::cerr << "Out of bounds access at index (" << i << ", " << j << ")." << std::endl;
                }
            }
        }
        return equalized_image;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
        throw;
    }
}
DimensionManipulator::~DimensionManipulator() = default;
cv::Mat DimensionManipulator::Gauss_filter(int radius, double sigma) {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        // 计算高斯模板尺寸
        cv::Size mask_size(radius * 2 + 1, radius * 2 + 1);
        cv::Mat mask = get_Gauss_mask(mask_size, sigma);
        // 进行高斯滤波
        cv::Mat result;
        cv::filter2D(this->gray_image, result, -1, mask);
        return result;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred in manipulator: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat DimensionManipulator::get_Gauss_mask(cv::Size size, double sigma) {
    // 创建高斯模板矩阵
    cv::Mat mask(size, CV_64F);
    int center_x = size.width / 2;
    int center_y = size.height / 2;
    double sum = 0.0;
    // 计算高斯模板值
    for (int i = 0; i < size.height; ++i) {
        for (int j = 0; j < size.width; ++j) {
            double x = pow(j - center_x, 2);
            double y = pow(i - center_y, 2);
            double g = exp(-(x + y) / (2 * sigma * sigma));
            mask.at<double>(i, j) = g;
            sum += g;
        }
    }
    // 归一化
    mask /= sum;
    return mask;
}

cv::Mat DimensionManipulator::median_filter(int radius) {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        // 计算中值模板尺寸
        cv::Size mask_size(radius * 2 + 1, radius * 2 + 1);
        // 创建中值模板矩阵
        cv::Mat mask(mask_size, CV_8U);
        // 计算中值滤波结果
        cv::Mat result;
        cv::medianBlur(this->gray_image, result, radius);
        return result;
    }catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat DimensionManipulator::laplacian_filter(int radius) {
    try {
        if (this->image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        // 应用拉普拉斯算子进行滤波
        cv::Mat result;
        cv::Laplacian(this->gray_image, result, CV_32F,  2*radius+1);
        return result;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat DimensionManipulator::sobel_filter(int radius) {
    try {
        if (this->image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat grad_x, grad_y;
        cv::Mat abs_grad_x, abs_grad_y;
        cv::Mat grad;
        cv::Sobel(gray_image, grad_x, CV_32F, 1, 0, 2 * radius + 1);
        cv::Sobel(gray_image, grad_y, CV_32F, 0, 1, 2 * radius + 1);
        // 计算梯度幅值
        cv::convertScaleAbs(grad_x, abs_grad_x);
        cv::convertScaleAbs(grad_y, abs_grad_y);
        cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
        return grad;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
    }
    return {};
}