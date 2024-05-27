//
// Created by Ayuan on 2024/3/4.
//

#ifndef QTIMAGEPROCESS_BASED_HPP
#define QTIMAGEPROCESS_BASED_HPP
#include <manipulator.hpp>
class ImageBasedManipulator: public Manipulator{
public:
    ~ImageBasedManipulator() override;
    explicit ImageBasedManipulator(std::string &image_path): Manipulator(image_path){};
    cv::Mat rotate(int angle);
    cv::Mat flip_horizontal();
    cv::Mat flip_vertical();
    cv::Mat resize(double scale_percent);
    cv::Mat gray();
    void display();
};
#endif //QTIMAGEPROCESS_BASED_HPP
