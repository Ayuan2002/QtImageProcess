/********************************************************************************
** Form generated from reading UI file 'licence_recognition.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENCE_RECOGNITION_H
#define UI_LICENCE_RECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_licence_recognition
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *layout;
    QLabel *TitleLabel;
    QGraphicsView *graphicsView;
    QHBoxLayout *ButtonLayout;
    QPushButton *Previous;
    QPushButton *Next;
    QPushButton *Finish;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *HintLabel;
    QLabel *LicenceLabel;

    void setupUi(QWidget *licence_recognition)
    {
        if (licence_recognition->objectName().isEmpty())
            licence_recognition->setObjectName("licence_recognition");
        licence_recognition->resize(936, 596);
        gridLayout = new QGridLayout(licence_recognition);
        gridLayout->setObjectName("gridLayout");
        layout = new QVBoxLayout();
        layout->setObjectName("layout");
        TitleLabel = new QLabel(licence_recognition);
        TitleLabel->setObjectName("TitleLabel");

        layout->addWidget(TitleLabel);

        graphicsView = new QGraphicsView(licence_recognition);
        graphicsView->setObjectName("graphicsView");

        layout->addWidget(graphicsView);

        ButtonLayout = new QHBoxLayout();
        ButtonLayout->setObjectName("ButtonLayout");
        Previous = new QPushButton(licence_recognition);
        Previous->setObjectName("Previous");

        ButtonLayout->addWidget(Previous);

        Next = new QPushButton(licence_recognition);
        Next->setObjectName("Next");

        ButtonLayout->addWidget(Next);

        Finish = new QPushButton(licence_recognition);
        Finish->setObjectName("Finish");

        ButtonLayout->addWidget(Finish);


        layout->addLayout(ButtonLayout);

        groupBox = new QGroupBox(licence_recognition);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        HintLabel = new QLabel(groupBox);
        HintLabel->setObjectName("HintLabel");

        horizontalLayout->addWidget(HintLabel);

        LicenceLabel = new QLabel(groupBox);
        LicenceLabel->setObjectName("LicenceLabel");

        horizontalLayout->addWidget(LicenceLabel);


        layout->addWidget(groupBox);


        gridLayout->addLayout(layout, 0, 0, 1, 1);


        retranslateUi(licence_recognition);

        QMetaObject::connectSlotsByName(licence_recognition);
    } // setupUi

    void retranslateUi(QWidget *licence_recognition)
    {
        licence_recognition->setWindowTitle(QCoreApplication::translate("licence_recognition", "licence_recognition", nullptr));
        TitleLabel->setText(QCoreApplication::translate("licence_recognition", "\345\216\237\345\247\213\350\275\246\347\211\214\345\233\276\347\211\207", nullptr));
        Previous->setText(QCoreApplication::translate("licence_recognition", "\344\270\212\344\270\200\346\255\245", nullptr));
        Next->setText(QCoreApplication::translate("licence_recognition", "\344\270\213\344\270\200\346\255\245", nullptr));
        Finish->setText(QCoreApplication::translate("licence_recognition", "\345\277\253\350\277\233\345\210\260\347\273\223\346\236\234", nullptr));
        groupBox->setTitle(QCoreApplication::translate("licence_recognition", "\350\275\246\347\211\214\350\257\206\345\210\253\347\273\223\346\236\234", nullptr));
        HintLabel->setText(QCoreApplication::translate("licence_recognition", "\350\275\246\347\211\214\345\217\267\357\274\232", nullptr));
        LicenceLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class licence_recognition: public Ui_licence_recognition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENCE_RECOGNITION_H
