//
// Created by Ayuan on 2024/3/19.
//
#ifndef QTIMAGEPROCESS_MAINWINDOW_H
#define QTIMAGEPROCESS_MAINWINDOW_H
#include "ui_mainwindow.h"
#include "based.hpp"
#include "globe_define_words.h"
#include <QFileDialog>
#include <windows.h>
#include <util.hpp>
#include <HistogramDialog.hpp>
#include <license_recognition_dialog.hpp>
class mainWindow : public QMainWindow, public Ui::mainWindow {
    Q_OBJECT
public:
    int spin_value=0;
    QGraphicsScene *left;
    QGraphicsScene *right;
    QVector<QDoubleSpinBox*> spin_box_list;
    QVector<QLabel*> label_list;
    QString source_file_name;
    bool is_operated=false;
    Manipulator* manipulator=nullptr;
    HistogramDialog *histogram_dialog;
    ProcessType type=EMPTY;
    explicit mainWindow(QWidget* parent = nullptr);
    void showWarning(const QString& message);
    void do_rotate(int angle);
    static void play_system_sound();
    void do_horizontal_flip();
    void do_vertical_flip();
    void do_gray();
    void do_resize(double scale_percent);
    void do_restore_group_box();
    void add_operate_items(int spin_boxes_nums,int label_nums,const QStringList& text_list,const QString& title);
    void remove_operate_items();
    void show_pixmap_in_right(const QPixmap& pixmap);
    void select_manipulator_pointer();
    //图像分割菜单实现方法
    void do_edge_detection();
    void do_line_detection();
    void do_threshold_process();
    //频率域菜单实现方法
    void do_fourier_transform();
    void do_low_pass_filter();
    //空间域菜单实现方法
    void do_histogram_equalization();
    void do_median_filter();
    void do_gauss_filter();
    void do_laplacian_filter();
    void do_sobel_filter();
    //形态学实现方法
    void do_dilation();
    void do_erosion();
    void do_opening();
    void do_closing();
    //艺术菜单实现方法
    void do_color_painting();
    void do_sketch();
    void do_old_photo();
private slots:
    void actionSave_triggered();
    void on_spinBox_valueChanged(int value);
    void on_actionOpenFile_triggered();
    void on_actionRotate_triggered();
    void on_Generate_clicked();
    void on_actionHorizontalFlip_triggered();
    void on_actionVerticalFlip_triggered();
    void on_actionGray_triggered();
    void on_actionResize_triggered();
    void on_actionRestore_triggered();
    void on_actionQuit_triggered();
    void on_actionSaveOther_triggered();
    void on_actionHistogram_triggered();
    void on_actionAddNoise_triggered();
    //图像分割菜单触发动作
    void on_actionEdgeDetection_triggered();
    void on_actionLineDetection_triggered();
    void on_actionThresholdProcess_triggered();
    //频率域菜单触发动作
    void on_actionFourier_triggered();
    void on_actionLowPassFilter_triggered();
    //空间域菜单触发动作
    void on_actionHistogramEqualization_triggered();
    void on_actionMedianFilter_triggered();
    void on_actionGaussFilter_triggered();
    void on_actionLaplacianFilter_triggered();
    void on_actionSobelFilter_triggered();
    //形态学菜单触发动作
    void on_actionDilation_triggered();
    void on_actionErosion_triggered();
    void on_actionOpening_triggered();
    void on_actionClosing_triggered();
    //车牌识别菜单触发动作
    void on_LicenceRecognition_triggered();
    //艺术效果菜单触发动作
    void on_actionColorPainting_triggered();
    void on_actionSketch_triggered();
    void on_actionOldPhoto_triggered();
};


#endif //QTIMAGEPROCESS_MAINWINDOW_H
