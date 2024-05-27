//
// Created by Ayuan on 2024/4/15.
//

#ifndef QTIMAGEPROCESS_DIMENSION_MANIPULATOR_HPP
#define QTIMAGEPROCESS_DIMENSION_MANIPULATOR_HPP
#include <manipulator.hpp>
class DimensionManipulator: public Manipulator {
private:
    cv::Mat gray_image;
public:
    DimensionManipulator();
    explicit DimensionManipulator(std::string & image_path);
    ~DimensionManipulator() override;
    cv::Mat histogram_equalization();
    cv::Mat Gauss_filter(int radius,double sigma);
    cv::Mat get_Gauss_mask(cv::Size size,double sigma);
    cv::Mat median_filter(int radius);
    cv::Mat laplacian_filter(int radius);
    cv::Mat sobel_filter(int radius);
};
#endif //QTIMAGEPROCESS_DIMENSION_MANIPULATOR_HPP
