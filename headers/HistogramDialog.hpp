//
// Created by Ayuan on 2024/4/9.
//

#ifndef QTIMAGEPROCESS_HISTOGRAMDIALOG_HPP
#define QTIMAGEPROCESS_HISTOGRAMDIALOG_HPP
#include <ui_histogramdialog.h>
class HistogramDialog:public QDialog,public Ui::HistogramDialog{
    Q_OBJECT
public:
    QGraphicsScene *histogramScene;
    explicit HistogramDialog(QWidget *parent = nullptr);
    ~HistogramDialog() override;
};



#endif //QTIMAGEPROCESS_HISTOGRAMDIALOG_HPP
