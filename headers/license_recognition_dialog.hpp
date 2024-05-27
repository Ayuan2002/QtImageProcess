//
// Created by Ayuan on 2024/4/21.
//

#ifndef QTIMAGEPROCESS_LICENSE_RECOGNITION_DIALOG_HPP
#define QTIMAGEPROCESS_LICENSE_RECOGNITION_DIALOG_HPP
#include <ui_licence_recognition_dialog.h>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QVector>
#include <licence_recognition_util.hpp>
static const QVector<QString> steps={"原始图像","灰度化图像","高斯滤波","sobel边缘检测","二值化",
                              "形态学操作","定位车牌区域","分割车牌字符","识别结果"};
class LicenseRecognitionDialog:public QDialog,public Ui::licence_recognition_dialog {
Q_OBJECT
private:
    QGraphicsScene* src;
    QGraphicsTextItem* hint;
    QString file_path;
    bool is_started=false;
    volatile unsigned int current_index=0;
    LicenceRecognition rec;
private slots:
    void mouse_clicked_in_view();
    void start_clicked();
    void next_clicked();
    void previous_clicked();
    void finish_clicked();
public:
    explicit LicenseRecognitionDialog(QWidget* parent=nullptr);
    ~LicenseRecognitionDialog()override;
    bool eventFilter(QObject *obj, QEvent * event)override;
    //根据进度索引更新视图
    void update_view();
    void update_graphics_view(const QPixmap& map);
};


#endif //QTIMAGEPROCESS_LICENSE_RECOGNITION_DIALOG_HPP
