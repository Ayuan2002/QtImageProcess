//
// Created by Ayuan on 2024/4/9.
//
#include <HistogramDialog.hpp>
HistogramDialog::HistogramDialog(QWidget *parent) : QDialog(parent), Ui::HistogramDialog(){
    setupUi(this);
    histogramScene = new QGraphicsScene(this);
}

HistogramDialog::~HistogramDialog() {
    delete histogramScene;
}
