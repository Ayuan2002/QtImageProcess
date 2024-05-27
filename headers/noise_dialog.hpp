//
// Created by Ayuan on 2024/4/16.
//

#ifndef QTIMAGEPROCESS_NOISE_DIALOG_HPP
#define QTIMAGEPROCESS_NOISE_DIALOG_HPP
#include <ui_add_noise_dialog.h>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
enum NoiseType{
    EMPTY_NOISE=0,
    SALT=1,
    GAUSSIAN,
    SPECKLE,
};
class NoiseDialog:public QDialog,public Ui::add_noise_dialog {
    Q_OBJECT
private:
    QGraphicsScene* src;
    QGraphicsScene* dst;
    QGraphicsTextItem* hint;
    NoiseType type=EMPTY_NOISE;
    QString file_path;
public:
    explicit NoiseDialog(QWidget *parent = nullptr);
    ~NoiseDialog() override;
    bool eventFilter(QObject *obj, QEvent * event)override;
    void show_noise_image(const QPixmap& map);
private slots:
    void mouse_clicked_in_src();
    void salt_noise_checked();
    void button_clicked();
    void gaussian_noise_checked();
    void speckle_noise_checked();
    void save_triggered();
};


#endif //QTIMAGEPROCESS_NOISE_DIALOG_HPP
