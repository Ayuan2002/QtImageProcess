//
// Created by Ayuan on 2024/4/24.
//

#ifndef QTIMAGEPROCESS_ARTS_MANIPULATOR_HPP
#define QTIMAGEPROCESS_ARTS_MANIPULATOR_HPP
#include <manipulator.hpp>
class ArtsManipulator : public Manipulator {
private :cv::Mat gray_image;
public:
    ~ArtsManipulator() override;
    ArtsManipulator();
    explicit ArtsManipulator(std::string &file_path);
    cv::Mat ColorPainting();
    cv::Mat Sketch();
    cv::Mat OldPhoto();
};
#endif //QTIMAGEPROCESS_ARTS_MANIPULATOR_HPP
