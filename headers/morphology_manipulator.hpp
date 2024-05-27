//
// Created by Ayuan on 2024/4/16.
//

#ifndef QTIMAGEPROCESS_MORPHOLOGY_MANIPULATOR_HPP
#define QTIMAGEPROCESS_MORPHOLOGY_MANIPULATOR_HPP
#include <manipulator.hpp>
class MorphologyManipulator: public Manipulator {
private:
    cv::Mat gray_image;
public:
    cv::Mat erosion(int radius);
    cv::Mat erosion(int radius,cv::Mat& input);
    cv::Mat dilation(int radius);
    cv::Mat dilation(int radius,cv::Mat& input);
    cv::Mat opening(int radius);
    cv::Mat closing(int radius);
    cv::Mat gradient(int radius);
    cv::Mat top_hat(int radius);
    cv::Mat black_hat(int radius);
    MorphologyManipulator();
    explicit MorphologyManipulator(std::string & image_path);
     ~MorphologyManipulator() override;
};
#endif //QTIMAGEPROCESS_MORPHOLOGY_MANIPULATOR_HPP
