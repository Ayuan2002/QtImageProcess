//
// Created by Ayuan on 2024/4/9.
//

#ifndef QTIMAGEPROCESS_SEGMENTATION_MANIPULATOR_HPP
#define QTIMAGEPROCESS_SEGMENTATION_MANIPULATOR_HPP

#include "manipulator.hpp"
class SegmentationManipulator: public Manipulator {
public:
    cv::Mat gray_image;
    ~SegmentationManipulator() override = default;
    SegmentationManipulator();
    explicit SegmentationManipulator(std::string &image_path);
    cv::Mat detect_edges(int low_threshold, int high_threshold);
    cv::Mat detect_lines(int low_threshold, int high_threshold);
    cv::Mat apply_threshold(int threshold_value);
};
#endif //QTIMAGEPROCESS_SEGMENTATION_MANIPULATOR_HPP
