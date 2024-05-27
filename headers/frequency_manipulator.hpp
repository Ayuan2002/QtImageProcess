//
// Created by Ayuan on 2024/4/13.
//

#ifndef QTIMAGEPROCESS_FREQUENCY_MANIPULATOR_HPP
#define QTIMAGEPROCESS_FREQUENCY_MANIPULATOR_HPP
#include <manipulator.hpp>
class FrequencyManipulator: public Manipulator {
private:
    cv::Mat gray_image;
public:
    FrequencyManipulator();
    explicit FrequencyManipulator(std::string & image_path);
    cv::Mat fourier_transform();
    cv::Mat low_pass_filter(int kernel_size);
};
#endif //QTIMAGEPROCESS_FREQUENCY_MANIPULATOR_HPP
