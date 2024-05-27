//
// Created by Ayuan on 2024/4/13.
//
#include <frequency_manipulator.hpp>

FrequencyManipulator::FrequencyManipulator() = default;

FrequencyManipulator::FrequencyManipulator(std::string &image_path) : Manipulator(image_path) {
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

cv::Mat FrequencyManipulator::fourier_transform() {
    try {
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        // 扩展图像到最佳尺寸
        int M = cv::getOptimalDFTSize(this->gray_image.rows);
        int N = cv::getOptimalDFTSize(this->gray_image.cols);
        cv::Mat padded;
        cv::copyMakeBorder(this->gray_image, padded, 0, M - this->gray_image.rows, 0, N - this->gray_image.cols,
                           cv::BORDER_CONSTANT, cv::Scalar::all(0));
        // 分配存储空间
        cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
        cv::Mat complexI;
        cv::merge(planes, 2, complexI);
        // 进行离散傅里叶变换
        cv::dft(complexI, complexI);
        // 将复数转换为幅值
        cv::split(complexI, planes);
        cv::magnitude(planes[0], planes[1], planes[0]);
        cv::Mat magnitudeImage = planes[0];
        // 对幅值进行对数尺度缩放
        magnitudeImage += cv::Scalar::all(1);
        cv::log(magnitudeImage, magnitudeImage);
        // 裁剪幅值图像
        magnitudeImage = magnitudeImage(cv::Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
        // 重新排列象限
        int cx = magnitudeImage.cols / 2;
        int cy = magnitudeImage.rows / 2;
        cv::Mat q0(magnitudeImage, cv::Rect(0, 0, cx, cy));
        cv::Mat q1(magnitudeImage, cv::Rect(cx, 0, cx, cy));
        cv::Mat q2(magnitudeImage, cv::Rect(0, cy, cx, cy));
        cv::Mat q3(magnitudeImage, cv::Rect(cx, cy, cx, cy));
        cv::Mat tmp;
        q0.copyTo(tmp);
        q3.copyTo(q0);
        tmp.copyTo(q3);
        q1.copyTo(tmp);
        q2.copyTo(q1);
        tmp.copyTo(q2);
        // 归一化
        cv::normalize(magnitudeImage, magnitudeImage, 0, 255, cv::NORM_MINMAX);
        return magnitudeImage;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return {};
}

cv::Mat FrequencyManipulator::low_pass_filter(int kernel_size) {
    try{
        if (this->gray_image.empty()) {
            throw std::runtime_error("Image data is empty.");
        }
        cv::Mat result= cv::Mat::zeros(this->gray_image.size(),this->gray_image.type());
        cv::Mat kernel=cv::getGaussianKernel(2*kernel_size+1,0.25);
        cv::filter2D(this->gray_image,result,this->gray_image.depth(),kernel,
                     cv::Point(-1,-1),0,cv::BORDER_DEFAULT);
        return result;
    }catch (const cv::Exception& e){
        std::cerr << "OpenCV error occurred in manipulator: " << e.what() << std::endl;
    }catch (const std::exception& e){
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return {};
}







