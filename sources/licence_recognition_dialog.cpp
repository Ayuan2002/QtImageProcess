//
// Created by Ayuan on 2024/4/21.
//
#include <license_recognition_dialog.hpp>
#include <QFileDialog>
#include <util.hpp>
LicenseRecognitionDialog::LicenseRecognitionDialog(QWidget *parent): QDialog(parent), Ui::licence_recognition_dialog() {
    setupUi(this);
    src=new QGraphicsScene(this);
    hint=new QGraphicsTextItem("鼠标单击打开图片");
    hint->setPos(20,20);
    src->addItem(hint);
    view->setScene(src);
    view->installEventFilter(this);
    connect(start, &QPushButton::clicked, this,&LicenseRecognitionDialog::start_clicked);
    connect(next, &QPushButton::clicked, this,&LicenseRecognitionDialog::next_clicked);
    connect(previous, &QPushButton::clicked, this,&LicenseRecognitionDialog::previous_clicked);
    connect(finish, &QPushButton::clicked, this,&LicenseRecognitionDialog::finish_clicked);
    explain->setText("1.打开图片\t2.点击开始按钮开始识别");
}

LicenseRecognitionDialog::~LicenseRecognitionDialog() = default;

bool LicenseRecognitionDialog::eventFilter(QObject *obj, QEvent *event) {
    if (obj==view && event->type()==QEvent::MouseButtonPress){
        auto* mouseEvent=dynamic_cast<QMouseEvent*>(event);
        if (mouseEvent->button()==Qt::LeftButton){
            mouse_clicked_in_view();
        }
    }
    return QDialog::eventFilter(obj, event);
}

void LicenseRecognitionDialog::mouse_clicked_in_view() {
    file_path = QFileDialog::getOpenFileName(this, tr("打开图片"),
                                             "",
                                             tr("Image Files (*.png *.jpg *.bmp *.jpeg *.gif)"));
    if (file_path.isEmpty()){
        return;
    }
    QPixmap map;
    if (!file_path.endsWith(".png")){
        map=ImageUtil::getPixmapFromFile(file_path);
    } else{
        map.load(file_path);
    }
    src->clear();
    src->addPixmap(map);
    view->setScene(src);
    is_started= false;
}

void LicenseRecognitionDialog::start_clicked() {
    if (file_path.isEmpty()){
        return;
    }
    current_index=0;
    std::string path=file_path.toStdString();
    rec=LicenceRecognition(path);
    int result=rec.recognizePlate();
    if (result<0){
        explain->setText("识别失败");
        return;
    }
    is_started= true;
    update_view();
}

void LicenseRecognitionDialog::finish_clicked() {
    if (!is_started)
        return;
    current_index=steps.size()-1;
    update_view();
}

void LicenseRecognitionDialog::next_clicked() {
    if (current_index==steps.size()-1)
        return;
    if (!is_started)
        return;
    current_index++;
    update_view();
}
void LicenseRecognitionDialog::previous_clicked() {
    if (!is_started)
        return;
    if (current_index==0)
        return;
    current_index--;
    update_view();
}
void LicenseRecognitionDialog::update_view() {
    if (!is_started){
        return;
    }
    explain->setText(steps[current_index]);
    QPixmap map;
    switch (current_index) {
        case 0:
            map=ImageUtil::getPixmapFromFile(file_path);
            update_graphics_view(map);
            break;
        case 1:
            map=ImageUtil::convertToQPixmap(rec.getGrayImage());
            update_graphics_view(map);
            break;
        case 2:
            map=ImageUtil::convertToQPixmap(rec.getGaussianBlurImage());
            update_graphics_view(map);
            break;
        case 3:
            map=ImageUtil::convertToQPixmap(rec.getSobelImage());
            update_graphics_view(map);
            break;
        case 4:
            map=ImageUtil::convertToQPixmap(rec.getBinaryImage());
            update_graphics_view(map);
            break;
        case 5:
            map=ImageUtil::convertToQPixmap(rec.getCloseImage());
            update_graphics_view(map);
            break;
        case 6:
            map=ImageUtil::convertToQPixmap(rec.getMarkedImage());
            update_graphics_view(map);
            break;
        case 7:
            map=ImageUtil::convertToQPixmap(rec.getPlateImage());
            update_graphics_view(map);
            break;
        case 8:
            map=ImageUtil::convertToQPixmap(rec.getPlateImage());
            update_graphics_view(map);
            plate->setText(QString::fromStdString(rec.getPlate()));
            break;
        default:
            break;
    }
}

void LicenseRecognitionDialog::update_graphics_view(const QPixmap& map) {
    src->clear();
    src->addPixmap(map);
    view->setScene(src);
}


