/********************************************************************************
** Form generated from reading UI file 'add_noise_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_NOISE_DIALOG_H
#define UI_ADD_NOISE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_add_noise_dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *srcView;
    QHBoxLayout *radioLayout;
    QRadioButton *Speckle;
    QRadioButton *Salt;
    QRadioButton *Gaussian;
    QPushButton *Clicked;
    QGraphicsView *targetView;
    QPushButton *Save;

    void setupUi(QDialog *add_noise_dialog)
    {
        if (add_noise_dialog->objectName().isEmpty())
            add_noise_dialog->setObjectName("add_noise_dialog");
        add_noise_dialog->resize(489, 707);
        verticalLayout_2 = new QVBoxLayout(add_noise_dialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        srcView = new QGraphicsView(add_noise_dialog);
        srcView->setObjectName("srcView");

        verticalLayout->addWidget(srcView);

        radioLayout = new QHBoxLayout();
        radioLayout->setObjectName("radioLayout");
        Speckle = new QRadioButton(add_noise_dialog);
        Speckle->setObjectName("Speckle");

        radioLayout->addWidget(Speckle);

        Salt = new QRadioButton(add_noise_dialog);
        Salt->setObjectName("Salt");

        radioLayout->addWidget(Salt);

        Gaussian = new QRadioButton(add_noise_dialog);
        Gaussian->setObjectName("Gaussian");

        radioLayout->addWidget(Gaussian);

        Clicked = new QPushButton(add_noise_dialog);
        Clicked->setObjectName("Clicked");

        radioLayout->addWidget(Clicked);


        verticalLayout->addLayout(radioLayout);

        targetView = new QGraphicsView(add_noise_dialog);
        targetView->setObjectName("targetView");

        verticalLayout->addWidget(targetView);

        Save = new QPushButton(add_noise_dialog);
        Save->setObjectName("Save");

        verticalLayout->addWidget(Save);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(add_noise_dialog);

        QMetaObject::connectSlotsByName(add_noise_dialog);
    } // setupUi

    void retranslateUi(QDialog *add_noise_dialog)
    {
        add_noise_dialog->setWindowTitle(QCoreApplication::translate("add_noise_dialog", "add_noise_dialog", nullptr));
        Speckle->setText(QCoreApplication::translate("add_noise_dialog", "\346\226\221\347\202\271\345\231\252\345\243\260", nullptr));
        Salt->setText(QCoreApplication::translate("add_noise_dialog", "\346\244\222\347\233\220\345\231\252\345\243\260", nullptr));
        Gaussian->setText(QCoreApplication::translate("add_noise_dialog", "\351\253\230\346\226\257\345\231\252\345\243\260", nullptr));
        Clicked->setText(QCoreApplication::translate("add_noise_dialog", "\347\241\256\345\256\232", nullptr));
        Save->setText(QCoreApplication::translate("add_noise_dialog", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_noise_dialog: public Ui_add_noise_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_NOISE_DIALOG_H
