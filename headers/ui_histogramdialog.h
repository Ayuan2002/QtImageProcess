/********************************************************************************
** Form generated from reading UI file 'histogramdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMDIALOG_H
#define UI_HISTOGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistogramDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *HistogramView;
    QFrame *Yline;
    QFrame *Xline;
    QLabel *Origin;
    QLabel *label;

    void setupUi(QDialog *HistogramDialog)
    {
        if (HistogramDialog->objectName().isEmpty())
            HistogramDialog->setObjectName("HistogramDialog");
        HistogramDialog->resize(712, 555);
        layoutWidget = new QWidget(HistogramDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(140, 10, 502, 511));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        HistogramView = new QGraphicsView(layoutWidget);
        HistogramView->setObjectName("HistogramView");
        HistogramView->setMinimumSize(QSize(500, 500));

        verticalLayout->addWidget(HistogramView);

        Yline = new QFrame(HistogramDialog);
        Yline->setObjectName("Yline");
        Yline->setGeometry(QRect(120, 10, 20, 511));
        Yline->setFrameShape(QFrame::VLine);
        Yline->setFrameShadow(QFrame::Sunken);
        Xline = new QFrame(HistogramDialog);
        Xline->setObjectName("Xline");
        Xline->setGeometry(QRect(130, 520, 521, 16));
        Xline->setFrameShape(QFrame::HLine);
        Xline->setFrameShadow(QFrame::Sunken);
        Origin = new QLabel(HistogramDialog);
        Origin->setObjectName("Origin");
        Origin->setGeometry(QRect(110, 520, 54, 16));
        label = new QLabel(HistogramDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(660, 520, 54, 16));

        retranslateUi(HistogramDialog);

        QMetaObject::connectSlotsByName(HistogramDialog);
    } // setupUi

    void retranslateUi(QDialog *HistogramDialog)
    {
        HistogramDialog->setWindowTitle(QCoreApplication::translate("HistogramDialog", "HistogramDialog", nullptr));
        Origin->setText(QCoreApplication::translate("HistogramDialog", "0", nullptr));
        label->setText(QCoreApplication::translate("HistogramDialog", "255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistogramDialog: public Ui_HistogramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMDIALOG_H
