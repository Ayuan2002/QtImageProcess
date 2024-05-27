/********************************************************************************
** Form generated from reading UI file 'licence_recognition_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENCE_RECOGNITION_DIALOG_H
#define UI_LICENCE_RECOGNITION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_licence_recognition_dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *view;
    QHBoxLayout *buttonLayout;
    QPushButton *start;
    QPushButton *previous;
    QPushButton *next;
    QPushButton *finish;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *text;
    QSpacerItem *horizontalSpacer;
    QLineEdit *plate;
    QLabel *explain;

    void setupUi(QDialog *licence_recognition_dialog)
    {
        if (licence_recognition_dialog->objectName().isEmpty())
            licence_recognition_dialog->setObjectName("licence_recognition_dialog");
        licence_recognition_dialog->resize(913, 598);
        gridLayout = new QGridLayout(licence_recognition_dialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        view = new QGraphicsView(licence_recognition_dialog);
        view->setObjectName("view");

        verticalLayout->addWidget(view);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        start = new QPushButton(licence_recognition_dialog);
        start->setObjectName("start");

        buttonLayout->addWidget(start);

        previous = new QPushButton(licence_recognition_dialog);
        previous->setObjectName("previous");

        buttonLayout->addWidget(previous);

        next = new QPushButton(licence_recognition_dialog);
        next->setObjectName("next");

        buttonLayout->addWidget(next);

        finish = new QPushButton(licence_recognition_dialog);
        finish->setObjectName("finish");

        buttonLayout->addWidget(finish);


        verticalLayout->addLayout(buttonLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        groupBox = new QGroupBox(licence_recognition_dialog);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        text = new QLabel(groupBox);
        text->setObjectName("text");

        horizontalLayout->addWidget(text);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        plate = new QLineEdit(groupBox);
        plate->setObjectName("plate");

        horizontalLayout->addWidget(plate);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        explain = new QLabel(licence_recognition_dialog);
        explain->setObjectName("explain");

        gridLayout->addWidget(explain, 0, 0, 1, 1, Qt::AlignHCenter);


        retranslateUi(licence_recognition_dialog);

    } // setupUi

    void retranslateUi(QDialog *licence_recognition_dialog)
    {
        licence_recognition_dialog->setWindowTitle(QCoreApplication::translate("licence_recognition_dialog", "licence_recognition_dialog", nullptr));
        start->setText(QCoreApplication::translate("licence_recognition_dialog", "\345\274\200\345\247\213\350\257\206\345\210\253", nullptr));
        previous->setText(QCoreApplication::translate("licence_recognition_dialog", "\344\270\212\344\270\200\346\255\245", nullptr));
        next->setText(QCoreApplication::translate("licence_recognition_dialog", "\344\270\213\344\270\200\346\255\245", nullptr));
        finish->setText(QCoreApplication::translate("licence_recognition_dialog", "\345\277\253\350\277\233\345\210\260\347\273\223\346\236\234", nullptr));
        groupBox->setTitle(QString());
        text->setText(QCoreApplication::translate("licence_recognition_dialog", "\350\275\246\347\211\214\345\217\267", nullptr));
        explain->setText(QCoreApplication::translate("licence_recognition_dialog", "\345\216\237\345\247\213\345\233\276\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class licence_recognition_dialog: public Ui_licence_recognition_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENCE_RECOGNITION_DIALOG_H
