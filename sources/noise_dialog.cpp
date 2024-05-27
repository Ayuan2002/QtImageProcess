//
// Created by Ayuan on 2024/4/16.
//
#include <noise_dialog.hpp>
#include <QFileDialog>
#include <util.hpp>
#include <QMessageBox>

NoiseDialog::NoiseDialog(QWidget *parent) : QDialog(parent), Ui::add_noise_dialog(){
    setupUi(this);
    src=new QGraphicsScene(this);
    dst=new QGraphicsScene(this);
    hint=new QGraphicsTextItem("鼠标单击打开图片");
    hint->setPos(20,20);
    src->addItem(hint);
    srcView->setScene(src);
    srcView->installEventFilter(this);
    connect(Salt,&QRadioButton::clicked,this,&NoiseDialog::salt_noise_checked);
    connect(Clicked,&QPushButton::clicked,this,&NoiseDialog::button_clicked);
    connect(Gaussian,&QRadioButton::clicked,this,&NoiseDialog::gaussian_noise_checked);
    connect(Speckle,&QRadioButton::clicked,this,&NoiseDialog::speckle_noise_checked);
    connect(Save,&QPushButton::clicked,this,&NoiseDialog::save_triggered);
}

NoiseDialog::~NoiseDialog() {
    delete src;
    delete dst;
}

void NoiseDialog::mouse_clicked_in_src() {
    file_path = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                                      "",
                                                      tr("Image Files (*.png *.jpg *.bmp *.jpeg *.gif)"));
    if(file_path.isEmpty())
        return;
    QPixmap pixmap(file_path);
    pixmap.scaled(srcView->width(),srcView->height(),Qt::KeepAspectRatio);
    src->clear();
    src->addPixmap(pixmap);
    srcView->setScene(src);
}

bool NoiseDialog::eventFilter(QObject *obj, QEvent *event) {
    if(obj==srcView && event->type()==QEvent::MouseButtonPress){
       auto* mouseEvent=dynamic_cast<QMouseEvent*>(event);
        if (mouseEvent->button()==Qt::LeftButton){
            mouse_clicked_in_src();
        }
    }
    return QDialog::eventFilter(obj, event);
}
void NoiseDialog::gaussian_noise_checked() {
    this->type=NoiseType::GAUSSIAN;
}
void NoiseDialog::salt_noise_checked() {
    this->type=NoiseType::SALT;
}

void NoiseDialog::button_clicked() {
    QPixmap map;
    switch (type) {
        case EMPTY_NOISE:
            break;
        case SALT:
            map=ImageUtil::addSaltNoise(file_path);
            break;
        case GAUSSIAN:
            map=ImageUtil::addGaussianNoise(file_path);
            break;
        case SPECKLE:
            map=ImageUtil::addSpeckleNoise(file_path);
            break;

    }
    show_noise_image(map);
}

void NoiseDialog::show_noise_image(const QPixmap &map) {
    if (map.isNull())
        return;
    dst->clear();
    dst->addPixmap(map);
    targetView->setScene(dst);
}

void NoiseDialog::speckle_noise_checked() {
    this->type=NoiseType::SPECKLE;
}



void NoiseDialog::save_triggered() {
    QString fileName =QFileDialog::getSaveFileName(this, tr("保存噪声图片"),
                                                   "noise.png",
                                                   tr("Images (*.png *.xpm *.jpg)"));
    if (fileName.isEmpty())
        return;
    QPixmap map=getPixmapFromScene(dst);
    if (map.isNull()){
        QMessageBox::warning(this, "提示", "请先添加噪声并且确保生成噪声图片！");
        return;
    }
    map.save(fileName);
    QMessageBox::information(this, "提示", "保存成功！");
}



