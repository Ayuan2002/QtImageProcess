//
// Created by Ayuan on 2024/3/19.
//
#include <QMessageBox>
#include "mainWindow.h"
#include "segmentation_manipulator.hpp"
#include "dimension_manipulator.hpp"
#include "morphology_manipulator.hpp"
#include "arts_manipulator.hpp"
#include <frequency_manipulator.hpp>
#include <QImageReader>
#include <noise_dialog.hpp>
void mainWindow::on_Generate_clicked() {
    if (source_file_name.isEmpty()){
        //提示先打开一个图像
        showWarning("请先打开一个图像文件");
        return;
    }
    if (is_operated){
        play_system_sound();
        return;
    }
    switch (type) {
        case EMPTY:
            showWarning("请选择您要进行的操作");
            return;
        case BASED_ROTATE:
            do_rotate(this->spin_value);
            break;
        case BASED_HORIZONTAL_FLIP:
            do_horizontal_flip();
            break;
        case BASED_VERTICAL_FLIP:
            do_vertical_flip();
            break;
        case BASED_RESIZE:
            do_resize(this->spin_value);
            break;
        case BASED_GRAY:
            do_gray();
            break;
        case SEGMENTATION_EDGE:
            do_edge_detection();
            break;
        case SEGMENTATION_THRESHOLD:
            do_threshold_process();
            break;
        case SEGMENTATION_LINE_DETECTION:
            do_line_detection();
            break;
        case FREQUENCY_FOURIER:
            do_fourier_transform();
            break;
        case FREQUENCY_LOW_PASS_FILTER:
            do_low_pass_filter();
            break;
        case DIMENSION_EQUALIZATION_HISTOGRAM:
            do_histogram_equalization();
            break;
        case DIMENSION_MEDIAN_FILTER:
            do_median_filter();
            break;
        case DIMENSION_GAUSSIAN_FILTER:
            do_gauss_filter();
            break;
        case DIMENSION_LAPLACIAN_FILTER:
            do_laplacian_filter();
            break;
        case DIMENSION_SOBEL_FILTER:
            do_sobel_filter();
            break;
        case MORPHOLOGY_DILATION:
            do_dilation();
            break;
        case MORPHOLOGY_EROSION:
            do_erosion();
            break;
        case MORPHOLOGY_OPENING:
            do_opening();
            break;
        case MORPHOLOGY_CLOSING:
            do_closing();
            break;
        case ART_COLOR_PAINTING:
            do_color_painting();
            break;
        case ART_OLD_PHOTO:
            do_old_photo();
            break;
        case ART_SKETCH:
            do_sketch();
            break;
    }
}
//构造函数
mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent),Ui::mainWindow() {
    setupUi(this);
    left = new QGraphicsScene(this);
    right = new QGraphicsScene(this);
    connect(actionOpenFile, &QAction::triggered, this, &mainWindow::on_actionOpenFile_triggered);
    connect(Generate,&QPushButton::clicked, this, &mainWindow::on_Generate_clicked);
    connect(actionRotate,&QAction::triggered, this, &mainWindow::on_actionRotate_triggered);
    connect(actionFlip_Horizontal,&QAction::triggered, this, &mainWindow::on_actionHorizontalFlip_triggered);
    connect(actionFlip_Vertical,&QAction::triggered, this, &mainWindow::on_actionVerticalFlip_triggered);
    connect(actionGray,&QAction::triggered, this, &mainWindow::on_actionGray_triggered);
    connect(actionScale,&QAction::triggered, this, &mainWindow::on_actionResize_triggered);
    connect(SpinBoxInput,&QSpinBox::valueChanged, this, &mainWindow::on_spinBox_valueChanged);
    connect(actionQuit,&QAction::triggered, this, &mainWindow::on_actionQuit_triggered);
    connect(actionSaveOther,&QAction::triggered, this, &mainWindow::on_actionSaveOther_triggered);
    connect(actionRestore,&QAction::triggered, this, &mainWindow::on_actionRestore_triggered);
    connect(actionHistogram,&QAction::triggered, this, &mainWindow::on_actionHistogram_triggered);
    connect(actionEdgeDetection,&QAction::triggered, this, &mainWindow::on_actionEdgeDetection_triggered);
    connect(actionLineDetection,&QAction::triggered, this, &mainWindow::on_actionLineDetection_triggered);
    connect(actionThresholdProcess,&QAction::triggered, this, &mainWindow::on_actionThresholdProcess_triggered);
    connect(actionFourier, &QAction::triggered, this, &mainWindow::on_actionFourier_triggered);
    connect(actionLowpassFilter, &QAction::triggered, this, &mainWindow::on_actionLowPassFilter_triggered);
    connect(actionHistogramEqualization, &QAction::triggered, this, &mainWindow::on_actionHistogramEqualization_triggered);
    connect(actionMedianFilter, &QAction::triggered, this, &mainWindow::on_actionMedianFilter_triggered);
    connect(actionGaussFilter, &QAction::triggered, this, &mainWindow::on_actionGaussFilter_triggered);
    connect(actionLaplacianFilter, &QAction::triggered, this, &mainWindow::on_actionLaplacianFilter_triggered);
    connect(actionSobelFilter, &QAction::triggered, this, &mainWindow::on_actionSobelFilter_triggered);
    connect(actionDilation, &QAction::triggered, this, &mainWindow::on_actionDilation_triggered);
    connect(actionErosion, &QAction::triggered, this, &mainWindow::on_actionErosion_triggered);
    connect(actionOpening, &QAction::triggered, this, &mainWindow::on_actionOpening_triggered);
    connect(actionClosing, &QAction::triggered, this, &mainWindow::on_actionClosing_triggered);
    connect(actionAddNoise, &QAction::triggered, this, &mainWindow::on_actionAddNoise_triggered);
    connect(actionSave, &QAction::triggered, this, &mainWindow::actionSave_triggered);
    connect(LicenseRecognition, &QMenu::aboutToShow, this, &mainWindow::on_LicenceRecognition_triggered);
    connect(actionColorPainting, &QAction::triggered, this, &mainWindow::on_actionColorPainting_triggered);
    connect(actionSketch, &QAction::triggered, this, &mainWindow::on_actionSketch_triggered);
    connect(actionOldPhoto, &QAction::triggered, this, &mainWindow::on_actionOldPhoto_triggered);
}
void mainWindow::on_actionOldPhoto_triggered() {
    do_restore_group_box();
    right->clear();
    type=ART_OLD_PHOTO;
    setWindowTitle("图像处理实验平台-怀旧照片"+source_file_name);
    is_operated= false;
}
void mainWindow::on_actionSketch_triggered() {
    do_restore_group_box();
    right->clear();
    type=ART_SKETCH;
    is_operated= false;
    setWindowTitle("图像处理实验平台-素描"+source_file_name);
}
void mainWindow::on_actionColorPainting_triggered() {
    do_restore_group_box();
    right->clear();
    type=ART_COLOR_PAINTING;
    setWindowTitle("图像处理实验平台-水彩艺术画"+source_file_name);
    is_operated= false;
}
void mainWindow::on_LicenceRecognition_triggered() {
    LicenseRecognitionDialog dialog(this);
    dialog.exec();
}
void mainWindow::on_actionAddNoise_triggered() {
    NoiseDialog dialog(this);
    dialog.setWindowTitle("添加噪声");
    dialog.exec();
}
void mainWindow::on_actionClosing_triggered() {
    do_restore_group_box();
    right->clear();
    type=MORPHOLOGY_CLOSING;
    setWindowTitle("图像处理实验平台-闭运算"+source_file_name);
    is_operated= false;
    groupBox->setTitle("闭运算-请输入闭运算核大小");
}
void mainWindow::on_actionOpening_triggered() {
    do_restore_group_box();
    right->clear();
    type=MORPHOLOGY_OPENING;
    is_operated= false;
    setWindowTitle("图像处理实验平台-开运算"+source_file_name);
    groupBox->setTitle("开运算-请输入开运算核大小");
}
void mainWindow::on_actionErosion_triggered() {
    do_restore_group_box();
    right->clear();
    type=MORPHOLOGY_EROSION;
    is_operated= false;
    setWindowTitle("图像处理实验平台-腐蚀"+source_file_name);
    groupBox->setTitle("腐蚀-请输入腐蚀核大小");
}
void mainWindow::on_actionDilation_triggered() {
    do_restore_group_box();
    right->clear();
    type=MORPHOLOGY_DILATION;
    setWindowTitle("图像处理实验平台-膨胀"+source_file_name);
    groupBox->setTitle("膨胀-请输入膨胀核大小");
}
void mainWindow::on_actionSobelFilter_triggered() {
    do_restore_group_box();
    right->clear();
    type=DIMENSION_SOBEL_FILTER;
    setWindowTitle("图像处理实验平台-索贝尔滤波"+source_file_name);
    groupBox->setTitle("索贝尔滤波-请输入索贝尔滤波半径");
}
void mainWindow::on_actionLaplacianFilter_triggered() {
    do_restore_group_box();
    right->clear();
    type=DIMENSION_LAPLACIAN_FILTER;
    is_operated= false;
    setWindowTitle("图像处理实验平台-拉普拉斯滤波"+source_file_name);
    groupBox->setTitle("拉普拉斯滤波-请输入拉普拉斯滤波半径");
}
void mainWindow::on_actionGaussFilter_triggered() {
    do_restore_group_box();
    right->clear();
    type=DIMENSION_GAUSSIAN_FILTER;
    setWindowTitle("图像处理实验平台-高斯滤波"+source_file_name);
    add_operate_items(1,2,{"高斯滤波核","高斯核标准差"},"高斯滤波参数");
    is_operated= false;
}
void mainWindow::on_actionMedianFilter_triggered() {
    do_restore_group_box();
    right->clear();
    type=DIMENSION_MEDIAN_FILTER;
    is_operated= false;
    setWindowTitle("图像处理实验平台-中值滤波"+source_file_name);
    groupBox->setTitle("中值滤波-请输入中值滤波半径");
}
void mainWindow::on_actionHistogramEqualization_triggered() {
    do_restore_group_box();
    right->clear();
    type=DIMENSION_EQUALIZATION_HISTOGRAM;
    is_operated= false;
    setWindowTitle("图像处理实验平台-直方图均衡化"+source_file_name);
    groupBox->setTitle("直方图均衡化");
}
void mainWindow::on_actionLowPassFilter_triggered() {
    do_restore_group_box();
    right->clear();
    type=FREQUENCY_LOW_PASS_FILTER;
    is_operated= false;
    setWindowTitle("图像处理实验平台-低通滤波"+source_file_name);
    groupBox->setTitle("低通滤波-请输入低通滤波核大小");
}
void mainWindow::on_actionFourier_triggered() {
    do_restore_group_box();
    right->clear();
    type=FREQUENCY_FOURIER;
    is_operated= false;
    setWindowTitle("图像处理实验平台-傅里叶变换"+source_file_name);
}
void mainWindow::on_actionThresholdProcess_triggered() {
    do_restore_group_box();
    right->clear();
    groupBox->setTitle("阈值处理——请输入阈值");
    type= SEGMENTATION_THRESHOLD;
    SpinBoxInput->setRange(0,255);
    is_operated= false;
    setWindowTitle("图像处理实验平台-阈值处理"+source_file_name);
}
void mainWindow::on_actionEdgeDetection_triggered() {
    do_restore_group_box();
    add_operate_items(1,2,{"低阈值","高阈值"},"canny边缘检测");
    right->clear();
    type=SEGMENTATION_EDGE;
    is_operated= false;
    setWindowTitle("图像处理实验平台-边缘检测"+source_file_name);
}
void mainWindow::on_actionLineDetection_triggered() {
    do_restore_group_box();
    add_operate_items(1,2,{"低阈值","高阈值"},"直线检测");
    right->clear();
    type= SEGMENTATION_LINE_DETECTION;
    is_operated= false;
    setWindowTitle("图像处理实验平台-直线检测"+source_file_name);
}
void mainWindow::on_actionHistogram_triggered() {
    if(source_file_name.isEmpty()){
        showWarning("错误: 您还没有打开一个图像文件，无法生成直方图");
        return;
    }
    histogram_dialog = new HistogramDialog(this);
    histogram_dialog->histogramScene->addPixmap(HistogramUtil::calculateGrayscaleHistogram(QImage(source_file_name)));
    histogram_dialog->HistogramView->setScene(histogram_dialog->histogramScene);
    histogram_dialog->setWindowTitle("灰度直方图");
    histogram_dialog->exec();
}
void mainWindow::on_actionOpenFile_triggered() {
    source_file_name = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Image Files(*.jpg *.png *.bmp *.jpeg *.gif *.tif))"));
    if (!source_file_name.isEmpty()) {
        QPixmap pixmap;
        if(source_file_name.endsWith(".png", Qt::CaseInsensitive)){
            QImageReader reader(source_file_name);
            reader.setDecideFormatFromContent(true);
            pixmap= QPixmap::fromImage(reader.read());
        }else{
            pixmap=ImageUtil::getPixmapFromFile(source_file_name);
        }
        if (!pixmap.isNull()) {
            left->clear();
            left->addPixmap(pixmap);
            GraphicLeft->setScene(left);
            setWindowTitle(source_file_name);
        } else {
            qDebug() << "QPixmap Failed to load image: " << source_file_name;
        }
    }
}

void mainWindow::on_actionRotate_triggered() {
    do_restore_group_box();
    right->clear();
    groupBox->setTitle("图像旋转-请输入角度(单位：度，最大值：360)");
    SpinBoxInput->setMaximum(360);
    is_operated= false;
    type=BASED_ROTATE;
    setWindowTitle("图像处理实验平台-图像旋转"+source_file_name);
}

void mainWindow::play_system_sound() {
    PlaySound(TEXT("SystemDefault"), nullptr, SND_ALIAS | SND_ASYNC);
}

void mainWindow::on_actionHorizontalFlip_triggered() {
    do_restore_group_box();
    right->clear();
    is_operated= false;
    type=BASED_HORIZONTAL_FLIP;
    setWindowTitle("图像处理实验平台-图像水平翻转"+source_file_name);
}

void mainWindow::on_actionVerticalFlip_triggered() {
    do_restore_group_box();
    right->clear();
    is_operated= false;
    type=BASED_VERTICAL_FLIP;
    setWindowTitle("图像处理实验平台-图像垂直翻转"+source_file_name);
}

void mainWindow::on_actionGray_triggered() {
    do_restore_group_box();
    right->clear();
    is_operated= false;
    type=BASED_GRAY;
    setWindowTitle("图像处理实验平台-图像灰度化"+source_file_name);
}


void mainWindow::on_actionResize_triggered() {
    do_restore_group_box();
    right->clear();
    is_operated= false;
    groupBox->setTitle("图像缩放-请输入缩放比例(单位%，最大值100)");
    SpinBoxInput->setMaximum(100);
    type=BASED_RESIZE;
    setWindowTitle("图像处理实验平台-图像缩放"+source_file_name);
}


void mainWindow::on_spinBox_valueChanged(int value) {
    is_operated= false;
    this->spin_value=value;
}

void mainWindow::on_actionRestore_triggered() {
    type=EMPTY;
    is_operated= false;
    source_file_name="";
    manipulator= nullptr;
    setWindowTitle("图像处理实验平台");
    do_restore_group_box();
    left->clear();
    right->clear();
}

void mainWindow::on_actionQuit_triggered() {
    this->close();
}
void mainWindow::actionSave_triggered() {
    if (!is_operated){
        showWarning("错误: 您还没有进行任何操作，无法保存！");
    }
    else{
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        "教学案例.png",
                                                        tr("Images (*.png *.xpm *.jpg)"));
        if (fileName.isEmpty())
            return;
        QPixmap pixmap;
        pixmap= getPixmapFromScene(right);
        if (pixmap.isNull()){
            showWarning("错误: 没有在右侧视图找到图片，无法保存！");
            return;
        }
        pixmap.save(fileName);
        QMessageBox::information(this, "提示", "保存成功！");
    }
}
void mainWindow::on_actionSaveOther_triggered() {
    if (!is_operated){
        showWarning("错误: 您还没有进行任何操作，无法保存！");
    }
    else{
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        "教学案例.png",
                                                        tr("Images (*.png *.xpm *.jpg)"));
        if (fileName.isEmpty())
            return;
        QPixmap pixmap;
        pixmap= getPixmapFromScene(right);
        if (pixmap.isNull()){
            showWarning("错误: 没有在右侧视图找到图片，无法保存！");
            return;
        }
        pixmap.save(fileName);
    }
}

void mainWindow::showWarning(const QString& message) {
    play_system_sound();
    QMessageBox::warning(this, "警告", message);
}

void mainWindow::do_rotate(int angle) {
    select_manipulator_pointer();
    QPixmap map=ImageUtil::convertToQPixmap(dynamic_cast<ImageBasedManipulator*>(manipulator)->rotate(angle));
    show_pixmap_in_right(map);
}
void mainWindow::do_gray() {
    select_manipulator_pointer();
    QPixmap map=ImageUtil::convertToQPixmap(dynamic_cast<ImageBasedManipulator*>(manipulator)->gray());
    if(map.isNull()){
        showWarning("错误: 无法灰度化图片，请检查图片是否为有效图片");
        return;
    }
    show_pixmap_in_right(map);
}
void mainWindow::do_resize(double scale_percent) {
    select_manipulator_pointer();
    QPixmap map=ImageUtil::convertToQPixmap(dynamic_cast<ImageBasedManipulator*>(manipulator)->resize(scale_percent));
    show_pixmap_in_right(map);
}
void mainWindow::do_vertical_flip() {
    select_manipulator_pointer();
    QPixmap map=ImageUtil::convertToQPixmap(dynamic_cast<ImageBasedManipulator*>(manipulator)->flip_vertical());
    show_pixmap_in_right(map);
}
void mainWindow::do_horizontal_flip() {
    select_manipulator_pointer();
    QPixmap map = ImageUtil::convertToQPixmap(
                dynamic_cast<ImageBasedManipulator *>(manipulator)->flip_horizontal());
    show_pixmap_in_right(map);
}

void mainWindow::do_restore_group_box() {
    remove_operate_items();
    groupBox->setTitle("操作参数");
    SpinBoxInput->setValue(0);
}
void mainWindow::add_operate_items(int spin_boxes_nums,int labels_nums,const QStringList& text_list,const QString& title) {
    if (labels_nums <= spin_boxes_nums || text_list.size() < labels_nums)
        return; // 检查参数合法性

    if (!spin_box_list.empty() || !label_list.empty())
        return; // 如果已经添加过，则不再添加
    this->groupBox->setTitle(title);
    auto initial_label = new QLabel(this->groupBox); // 初始的 label
    initial_label->setText(text_list[0]);
    initial_label->setAlignment(Qt::AlignCenter);
    label_list.push_back(initial_label);
    this->groupBox->layout()->addWidget(initial_label);

    for (int i = 1; i < labels_nums; ++i) { // 从1开始，因为第一个label已经添加了
        auto label = new QLabel(text_list[i], this->groupBox);
        label->setAlignment(Qt::AlignCenter);
        label_list.push_back(label);
        auto spin_box = new QDoubleSpinBox(this->groupBox);
        spin_box->setMinimum(0);
        spin_box->setMaximum(500);
        spin_box->setValue(0);
        spin_box_list.push_back(spin_box);
        // 添加 label 和 spin box 到布局中
        this->groupBox->layout()->addWidget(spin_box);
        this->groupBox->layout()->addWidget(label);
    }
}
void mainWindow::remove_operate_items() {
    if (spin_box_list.empty())
        return;
    for (auto & i : spin_box_list){
        this->groupBox->layout()->removeWidget(i);
        i->deleteLater();
    }
    for (auto & j : label_list){
        this->groupBox->layout()->removeWidget(j);
        j->deleteLater();
    }
    spin_box_list.clear();
    label_list.clear();
}
void mainWindow::do_edge_detection() {
    select_manipulator_pointer();
    QPixmap map;
    int high_threshold=spin_box_list[0]->value();
    map=ImageUtil::convertToQPixmap(dynamic_cast<SegmentationManipulator*>(manipulator)->detect_edges(spin_value,high_threshold));
    show_pixmap_in_right(map);
}
void mainWindow::do_line_detection() {
    select_manipulator_pointer();
    int high_threshold=spin_box_list[0]->value();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<SegmentationManipulator*>(manipulator)->detect_lines(spin_value,high_threshold));
    show_pixmap_in_right(map);
}
void mainWindow::do_threshold_process() {
    if (spin_value==0||spin_value==255){
        showWarning("错误: 无法进行阈值处理，阈值不能为0或者255");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<SegmentationManipulator*>(manipulator)->apply_threshold(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_low_pass_filter() {
    if (spin_value%2==0){
        showWarning("错误: 无法进行低通滤波，滤波半径大小必须为奇数");
        return;
    }
    if(spin_value>=15){
        showWarning("错误: 无法进行低通滤波，您输入的滤波半径过大");
        return;
    }else if(spin_value==0){
        showWarning("您还未输入任何滤波半径，请输入滤波半径");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<FrequencyManipulator*>(manipulator)->low_pass_filter(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_fourier_transform() {
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<FrequencyManipulator*>(manipulator)->fourier_transform(),5);
    show_pixmap_in_right(map);
}

void mainWindow::do_histogram_equalization() {
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<DimensionManipulator*>(manipulator)->histogram_equalization());
    show_pixmap_in_right(map);
}
void mainWindow::do_median_filter() {
    if (spin_value%2==0){
        showWarning("错误: 无法进行中值滤波，滤波半径大小必须为奇数");
        return;
    }
    if(spin_value>=15){
        showWarning("错误: 无法进行中值滤波，您输入的滤波半径过大");
        return;
    }else if(spin_value==0){
        showWarning("您还未输入任何滤波半径，请输入滤波半径");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<DimensionManipulator*>(manipulator)->median_filter(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_gauss_filter() {
    if (spin_value%2==0){
        showWarning("错误: 无法进行高斯滤波，滤波半径大小必须为奇数");
        return;
    }
    if(spin_value>=15){
        showWarning("错误: 无法进行高斯滤波，您输入的滤波半径过大");
        return;
    }else if(spin_value==0){
        showWarning("您还未输入任何滤波半径，请输入滤波半径");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<DimensionManipulator*>(manipulator)->Gauss_filter(spin_value,spin_box_list[0]->value()));
    show_pixmap_in_right(map);
}
void mainWindow::do_laplacian_filter() {
    if (spin_value%2==0){
        showWarning("错误: 无法进行拉普拉斯滤波，滤波半径大小必须为奇数");
        return;
    }
    if(spin_value>=15){
        showWarning("错误: 无法进行拉普拉斯滤波，您输入的滤波半径过大");
        return;
    }else if(spin_value==0){
        showWarning("您还未输入任何滤波半径，请输入滤波半径");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<DimensionManipulator*>(manipulator)->laplacian_filter(spin_value),5);
    show_pixmap_in_right(map);
}

void mainWindow::do_sobel_filter() {
    if (spin_value%2==0){
        showWarning("错误: 无法进行拉普拉斯滤波，滤波半径大小必须为奇数");
        return;
    }
    if(spin_value>=15){
        showWarning("错误: 无法进行拉普拉斯滤波，您输入的滤波半径过大");
        return;
    }else if(spin_value==0){
        showWarning("您还未输入任何滤波半径，请输入滤波半径");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<DimensionManipulator*>(manipulator)->sobel_filter(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_dilation() {
    if (spin_value==0){
        showWarning("您还没有输入膨胀核");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<MorphologyManipulator*>(manipulator)->dilation(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_erosion() {
    if (spin_value==0){
        showWarning("您还没有输入腐蚀核");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<MorphologyManipulator*>(manipulator)->erosion(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_opening() {
    if (spin_value==0){
        showWarning("您还没有输入开运算核");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<MorphologyManipulator*>(manipulator)->opening(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_closing() {
    if (spin_value==0){
        showWarning("您还没有输入闭运算核");
        return;
    }
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<MorphologyManipulator*>(manipulator)->closing(spin_value));
    show_pixmap_in_right(map);
}
void mainWindow::do_color_painting() {
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<ArtsManipulator*>(manipulator)->ColorPainting());
    show_pixmap_in_right(map);
}
void mainWindow::do_sketch() {
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<ArtsManipulator*>(manipulator)->Sketch());
    show_pixmap_in_right(map);
}
void mainWindow::do_old_photo() {
    select_manipulator_pointer();
    QPixmap map;
    map=ImageUtil::convertToQPixmap(dynamic_cast<ArtsManipulator*>(manipulator)->OldPhoto());
    show_pixmap_in_right(map);
}
void mainWindow::show_pixmap_in_right(const QPixmap &pixmap) {
    right->clear();
    right->addPixmap(pixmap);
    GraphicRight->setScene(right);
    is_operated=true;
}
void mainWindow::select_manipulator_pointer() {
    if (manipulator!= nullptr){
        delete manipulator;
        manipulator= nullptr;
    }
    std::string path= source_file_name.toStdString();
    switch (type) {
        case EMPTY:
            throw std::runtime_error("未选择操作类型");
            break;
        case BASED_ROTATE:
        case BASED_HORIZONTAL_FLIP:
        case BASED_VERTICAL_FLIP:
        case BASED_RESIZE:
        case BASED_GRAY:
            manipulator=new ImageBasedManipulator(path);
            break;
        case SEGMENTATION_EDGE:
        case SEGMENTATION_THRESHOLD:
        case SEGMENTATION_LINE_DETECTION:
            manipulator=new SegmentationManipulator(path);
            break;
        case FREQUENCY_FOURIER:
        case FREQUENCY_LOW_PASS_FILTER:
            manipulator=new FrequencyManipulator(path);
            break;
        case DIMENSION_EQUALIZATION_HISTOGRAM:
        case DIMENSION_MEDIAN_FILTER:
        case DIMENSION_GAUSSIAN_FILTER:
        case DIMENSION_LAPLACIAN_FILTER:
        case DIMENSION_SOBEL_FILTER:
            manipulator=new DimensionManipulator(path);
            break;
        case MORPHOLOGY_DILATION:
        case MORPHOLOGY_EROSION:
        case MORPHOLOGY_OPENING:
        case MORPHOLOGY_CLOSING:
            manipulator=new MorphologyManipulator(path);
            break;
        case ART_COLOR_PAINTING:
        case ART_OLD_PHOTO:
        case ART_SKETCH:
            manipulator=new ArtsManipulator(path);
            break;
    }
}


