
#ifndef QTIMAGEPROCESS_UTIL_HPP
#define QTIMAGEPROCESS_UTIL_HPP
#include <QPixmap>
#include <QPainter>
#include <opencv2/core/mat.hpp>
#include <QGraphicsScene>
#include <QGraphicsItem>
class HistogramUtil {
public:
static QPixmap calculateGrayscaleHistogram(const QImage &image);
};
class ImageUtil {
public:
    static QPixmap convertToQPixmap(const cv::Mat &image);
    static QPixmap convertToQPixmap(const cv::Mat &image, int);
    static QPixmap addSaltNoise(const QString& input);
    static void addSaltNoiseGray(cv::Mat &image);
    static void addSaltNoiseColor(cv::Mat &image);
    static void addSaltNoiseWithAlpha(cv::Mat &image);
    static QPixmap addGaussianNoise(const QString& input);
    static QPixmap addSpeckleNoise(const QString& input);
    static QPixmap addSimulationNoise(const QString& input);
    static QPixmap getPixmapFromFile(const QString& filePath);
};
static QPixmap getPixmapFromScene(QGraphicsScene *scene) {
    // 遍历场景中的每个项目
            foreach (QGraphicsItem *item, scene->items()) {
            // 检查项目是否为QGraphicsPixmapItem类型
            auto *pixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem*>(item);
            if (pixmapItem) {
                // 如果找到了QGraphicsPixmapItem，返回其对应的pixmap
                return pixmapItem->pixmap();
            }
        }
    return {};
}

#endif //QTIMAGEPROCESS_UTIL_HPP
