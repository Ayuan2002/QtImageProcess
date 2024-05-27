/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *actionOpenFile;
    QAction *actionSave;
    QAction *actionSaveOther;
    QAction *actionQuit;
    QAction *actionRotate;
    QAction *actionFlip_Horizontal;
    QAction *actionFlip_Vertical;
    QAction *actionScale;
    QAction *actionGray;
    QAction *actionRestore;
    QAction *actionHistogram;
    QAction *actionEdgeDetection;
    QAction *actionLineDetection;
    QAction *actionThresholdProcess;
    QAction *actionFourier;
    QAction *actionHistogramEqualization;
    QAction *actionDilation;
    QAction *actionErosion;
    QAction *actionOpening;
    QAction *actionClosing;
    QAction *actionAddNoise;
    QAction *actionMedianFilter;
    QAction *actionGaussFilter;
    QAction *actionLaplacianFilter;
    QAction *actionSobelFilter;
    QAction *actionColorPainting;
    QAction *actionOldPhoto;
    QAction *actionSketch;
    QAction *actionLowpassFilter;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *Center;
    QHBoxLayout *ImageLayout;
    QGraphicsView *GraphicLeft;
    QGraphicsView *GraphicRight;
    QHBoxLayout *SettingLayout;
    QVBoxLayout *LeftLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QSpinBox *SpinBoxInput;
    QVBoxLayout *RightLayout;
    QPushButton *Generate;
    QMenuBar *menubar;
    QMenu *FileMenu;
    QMenu *BasedMenu;
    QMenu *SegmentationMenu;
    QMenu *FrequencyMenu;
    QMenu *DimensionMenu;
    QMenu *SmoothingMenu;
    QMenu *SharpenMenu;
    QMenu *MorphologyMenu;
    QMenu *ArtsMenu;
    QMenu *LicenseRecognition;
    QMenu *SettingMenu;
    QMenu *AboutMenu;
    QToolBar *toolBar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName("mainWindow");
        mainWindow->resize(1055, 697);
        actionOpenFile = new QAction(mainWindow);
        actionOpenFile->setObjectName("actionOpenFile");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon);
        actionOpenFile->setMenuRole(QAction::ApplicationSpecificRole);
        actionSave = new QAction(mainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/diskette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSaveOther = new QAction(mainWindow);
        actionSaveOther->setObjectName("actionSaveOther");
        actionQuit = new QAction(mainWindow);
        actionQuit->setObjectName("actionQuit");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon2);
        actionQuit->setMenuRole(QAction::QuitRole);
        actionRotate = new QAction(mainWindow);
        actionRotate->setObjectName("actionRotate");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon3);
        actionFlip_Horizontal = new QAction(mainWindow);
        actionFlip_Horizontal->setObjectName("actionFlip_Horizontal");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/flip-h.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlip_Horizontal->setIcon(icon4);
        actionFlip_Vertical = new QAction(mainWindow);
        actionFlip_Vertical->setObjectName("actionFlip_Vertical");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/flip-v.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlip_Vertical->setIcon(icon5);
        actionScale = new QAction(mainWindow);
        actionScale->setObjectName("actionScale");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/resize.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale->setIcon(icon6);
        actionGray = new QAction(mainWindow);
        actionGray->setObjectName("actionGray");
        actionRestore = new QAction(mainWindow);
        actionRestore->setObjectName("actionRestore");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/restore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestore->setIcon(icon7);
        actionHistogram = new QAction(mainWindow);
        actionHistogram->setObjectName("actionHistogram");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/bar-chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistogram->setIcon(icon8);
        actionEdgeDetection = new QAction(mainWindow);
        actionEdgeDetection->setObjectName("actionEdgeDetection");
        actionLineDetection = new QAction(mainWindow);
        actionLineDetection->setObjectName("actionLineDetection");
        actionThresholdProcess = new QAction(mainWindow);
        actionThresholdProcess->setObjectName("actionThresholdProcess");
        actionFourier = new QAction(mainWindow);
        actionFourier->setObjectName("actionFourier");
        actionHistogramEqualization = new QAction(mainWindow);
        actionHistogramEqualization->setObjectName("actionHistogramEqualization");
        actionDilation = new QAction(mainWindow);
        actionDilation->setObjectName("actionDilation");
        actionErosion = new QAction(mainWindow);
        actionErosion->setObjectName("actionErosion");
        actionOpening = new QAction(mainWindow);
        actionOpening->setObjectName("actionOpening");
        actionClosing = new QAction(mainWindow);
        actionClosing->setObjectName("actionClosing");
        actionAddNoise = new QAction(mainWindow);
        actionAddNoise->setObjectName("actionAddNoise");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/noise.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddNoise->setIcon(icon9);
        actionMedianFilter = new QAction(mainWindow);
        actionMedianFilter->setObjectName("actionMedianFilter");
        actionGaussFilter = new QAction(mainWindow);
        actionGaussFilter->setObjectName("actionGaussFilter");
        actionLaplacianFilter = new QAction(mainWindow);
        actionLaplacianFilter->setObjectName("actionLaplacianFilter");
        actionSobelFilter = new QAction(mainWindow);
        actionSobelFilter->setObjectName("actionSobelFilter");
        actionColorPainting = new QAction(mainWindow);
        actionColorPainting->setObjectName("actionColorPainting");
        actionOldPhoto = new QAction(mainWindow);
        actionOldPhoto->setObjectName("actionOldPhoto");
        actionSketch = new QAction(mainWindow);
        actionSketch->setObjectName("actionSketch");
        actionLowpassFilter = new QAction(mainWindow);
        actionLowpassFilter->setObjectName("actionLowpassFilter");
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        Center = new QVBoxLayout();
        Center->setObjectName("Center");
        ImageLayout = new QHBoxLayout();
        ImageLayout->setObjectName("ImageLayout");
        GraphicLeft = new QGraphicsView(centralwidget);
        GraphicLeft->setObjectName("GraphicLeft");

        ImageLayout->addWidget(GraphicLeft);

        GraphicRight = new QGraphicsView(centralwidget);
        GraphicRight->setObjectName("GraphicRight");

        ImageLayout->addWidget(GraphicRight);


        Center->addLayout(ImageLayout);

        SettingLayout = new QHBoxLayout();
        SettingLayout->setObjectName("SettingLayout");
        LeftLayout = new QVBoxLayout();
        LeftLayout->setObjectName("LeftLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        SpinBoxInput = new QSpinBox(groupBox);
        SpinBoxInput->setObjectName("SpinBoxInput");

        verticalLayout->addWidget(SpinBoxInput);


        LeftLayout->addWidget(groupBox);


        SettingLayout->addLayout(LeftLayout);

        RightLayout = new QVBoxLayout();
        RightLayout->setObjectName("RightLayout");
        Generate = new QPushButton(centralwidget);
        Generate->setObjectName("Generate");

        RightLayout->addWidget(Generate, 0, Qt::AlignVCenter);


        SettingLayout->addLayout(RightLayout);


        Center->addLayout(SettingLayout);


        verticalLayout_2->addLayout(Center);

        mainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1055, 22));
        FileMenu = new QMenu(menubar);
        FileMenu->setObjectName("FileMenu");
        BasedMenu = new QMenu(menubar);
        BasedMenu->setObjectName("BasedMenu");
        SegmentationMenu = new QMenu(menubar);
        SegmentationMenu->setObjectName("SegmentationMenu");
        FrequencyMenu = new QMenu(menubar);
        FrequencyMenu->setObjectName("FrequencyMenu");
        DimensionMenu = new QMenu(menubar);
        DimensionMenu->setObjectName("DimensionMenu");
        SmoothingMenu = new QMenu(DimensionMenu);
        SmoothingMenu->setObjectName("SmoothingMenu");
        SharpenMenu = new QMenu(DimensionMenu);
        SharpenMenu->setObjectName("SharpenMenu");
        MorphologyMenu = new QMenu(menubar);
        MorphologyMenu->setObjectName("MorphologyMenu");
        ArtsMenu = new QMenu(menubar);
        ArtsMenu->setObjectName("ArtsMenu");
        LicenseRecognition = new QMenu(menubar);
        LicenseRecognition->setObjectName("LicenseRecognition");
        SettingMenu = new QMenu(menubar);
        SettingMenu->setObjectName("SettingMenu");
        AboutMenu = new QMenu(menubar);
        AboutMenu->setObjectName("AboutMenu");
        mainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(mainWindow);
        toolBar->setObjectName("toolBar");
        mainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(FileMenu->menuAction());
        menubar->addAction(SettingMenu->menuAction());
        menubar->addAction(BasedMenu->menuAction());
        menubar->addAction(SegmentationMenu->menuAction());
        menubar->addAction(FrequencyMenu->menuAction());
        menubar->addAction(DimensionMenu->menuAction());
        menubar->addAction(MorphologyMenu->menuAction());
        menubar->addAction(ArtsMenu->menuAction());
        menubar->addAction(LicenseRecognition->menuAction());
        menubar->addAction(AboutMenu->menuAction());
        FileMenu->addAction(actionOpenFile);
        FileMenu->addAction(actionSave);
        FileMenu->addAction(actionSaveOther);
        FileMenu->addAction(actionQuit);
        BasedMenu->addAction(actionRotate);
        BasedMenu->addAction(actionFlip_Horizontal);
        BasedMenu->addAction(actionFlip_Vertical);
        BasedMenu->addAction(actionScale);
        BasedMenu->addAction(actionGray);
        SegmentationMenu->addAction(actionEdgeDetection);
        SegmentationMenu->addAction(actionLineDetection);
        SegmentationMenu->addAction(actionThresholdProcess);
        FrequencyMenu->addAction(actionFourier);
        FrequencyMenu->addAction(actionLowpassFilter);
        DimensionMenu->addAction(actionHistogramEqualization);
        DimensionMenu->addAction(SmoothingMenu->menuAction());
        DimensionMenu->addAction(SharpenMenu->menuAction());
        SmoothingMenu->addAction(actionMedianFilter);
        SmoothingMenu->addAction(actionGaussFilter);
        SharpenMenu->addAction(actionLaplacianFilter);
        SharpenMenu->addAction(actionSobelFilter);
        MorphologyMenu->addAction(actionDilation);
        MorphologyMenu->addAction(actionErosion);
        MorphologyMenu->addAction(actionOpening);
        MorphologyMenu->addAction(actionClosing);
        ArtsMenu->addAction(actionColorPainting);
        ArtsMenu->addAction(actionOldPhoto);
        ArtsMenu->addAction(actionSketch);
        SettingMenu->addAction(actionRestore);
        SettingMenu->addAction(actionHistogram);
        SettingMenu->addAction(actionAddNoise);
        toolBar->addAction(actionOpenFile);
        toolBar->addAction(actionRestore);
        toolBar->addAction(actionHistogram);
        toolBar->addAction(actionAddNoise);

        retranslateUi(mainWindow);

    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "mainWindow", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("mainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenFile->setToolTip(QCoreApplication::translate("mainWindow", "\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave->setText(QCoreApplication::translate("mainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("mainWindow", "save", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSaveOther->setText(QCoreApplication::translate("mainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        actionQuit->setText(QCoreApplication::translate("mainWindow", "\351\200\200\345\207\272", nullptr));
        actionRotate->setText(QCoreApplication::translate("mainWindow", "\346\227\213\350\275\254", nullptr));
        actionFlip_Horizontal->setText(QCoreApplication::translate("mainWindow", "\346\260\264\345\271\263\347\277\273\350\275\254", nullptr));
        actionFlip_Vertical->setText(QCoreApplication::translate("mainWindow", "\345\236\202\347\233\264\347\277\273\350\275\254", nullptr));
        actionScale->setText(QCoreApplication::translate("mainWindow", "\347\274\251\346\224\276", nullptr));
        actionGray->setText(QCoreApplication::translate("mainWindow", "\347\201\260\345\272\246\345\214\226", nullptr));
        actionRestore->setText(QCoreApplication::translate("mainWindow", "\346\201\242\345\244\215", nullptr));
        actionHistogram->setText(QCoreApplication::translate("mainWindow", "\347\233\264\346\226\271\345\233\276", nullptr));
        actionEdgeDetection->setText(QCoreApplication::translate("mainWindow", "\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        actionLineDetection->setText(QCoreApplication::translate("mainWindow", "\347\233\264\347\272\277\346\243\200\346\265\213", nullptr));
        actionThresholdProcess->setText(QCoreApplication::translate("mainWindow", "\351\230\210\345\200\274\345\244\204\347\220\206", nullptr));
        actionFourier->setText(QCoreApplication::translate("mainWindow", "\345\202\205\351\207\214\345\217\266\345\217\230\346\215\242", nullptr));
        actionHistogramEqualization->setText(QCoreApplication::translate("mainWindow", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241", nullptr));
        actionDilation->setText(QCoreApplication::translate("mainWindow", "\350\206\250\350\203\200", nullptr));
        actionErosion->setText(QCoreApplication::translate("mainWindow", "\350\205\220\350\232\200", nullptr));
        actionOpening->setText(QCoreApplication::translate("mainWindow", "\345\274\200\350\277\220\347\256\227", nullptr));
        actionClosing->setText(QCoreApplication::translate("mainWindow", "\351\227\255\350\277\220\347\256\227", nullptr));
        actionAddNoise->setText(QCoreApplication::translate("mainWindow", "\346\267\273\345\212\240\345\231\252\345\243\260", nullptr));
#if QT_CONFIG(tooltip)
        actionAddNoise->setToolTip(QCoreApplication::translate("mainWindow", "\345\231\252\345\243\260", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMedianFilter->setText(QCoreApplication::translate("mainWindow", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
        actionGaussFilter->setText(QCoreApplication::translate("mainWindow", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
        actionLaplacianFilter->setText(QCoreApplication::translate("mainWindow", "Laplacian\346\273\244\346\263\242", nullptr));
        actionSobelFilter->setText(QCoreApplication::translate("mainWindow", "Sobel\346\273\244\346\263\242", nullptr));
        actionColorPainting->setText(QCoreApplication::translate("mainWindow", "\346\260\264\345\275\251\347\224\273", nullptr));
        actionOldPhoto->setText(QCoreApplication::translate("mainWindow", "\346\200\200\346\227\247", nullptr));
#if QT_CONFIG(tooltip)
        actionOldPhoto->setToolTip(QCoreApplication::translate("mainWindow", "\346\200\200\346\227\247", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSketch->setText(QCoreApplication::translate("mainWindow", "\347\264\240\346\217\217", nullptr));
        actionLowpassFilter->setText(QCoreApplication::translate("mainWindow", "\344\275\216\351\200\232\346\273\244\346\263\242\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mainWindow", "\346\223\215\344\275\234\345\217\202\346\225\260", nullptr));
        Generate->setText(QCoreApplication::translate("mainWindow", "\347\224\237\346\210\220", nullptr));
        FileMenu->setTitle(QCoreApplication::translate("mainWindow", "\346\226\207\344\273\266", nullptr));
        BasedMenu->setTitle(QCoreApplication::translate("mainWindow", "\345\237\272\346\234\254\346\223\215\344\275\234", nullptr));
        SegmentationMenu->setTitle(QCoreApplication::translate("mainWindow", "\345\233\276\345\203\217\345\210\206\345\211\262", nullptr));
        FrequencyMenu->setTitle(QCoreApplication::translate("mainWindow", "\351\242\221\347\216\207\345\237\237\347\256\227\346\263\225", nullptr));
        DimensionMenu->setTitle(QCoreApplication::translate("mainWindow", "\347\251\272\351\227\264\345\237\237\347\256\227\346\263\225", nullptr));
        SmoothingMenu->setTitle(QCoreApplication::translate("mainWindow", "\345\271\263\346\273\221\346\273\244\346\263\242\345\231\250", nullptr));
        SharpenMenu->setTitle(QCoreApplication::translate("mainWindow", "\351\224\220\345\214\226\346\273\244\346\263\242\345\231\250", nullptr));
        MorphologyMenu->setTitle(QCoreApplication::translate("mainWindow", "\345\275\242\346\200\201\345\255\246\346\223\215\344\275\234", nullptr));
        ArtsMenu->setTitle(QCoreApplication::translate("mainWindow", "\350\211\272\346\234\257\346\225\210\346\236\234", nullptr));
        LicenseRecognition->setTitle(QCoreApplication::translate("mainWindow", "\350\275\246\347\211\214\350\257\206\345\210\253", nullptr));
        SettingMenu->setTitle(QCoreApplication::translate("mainWindow", "\347\274\226\350\276\221", nullptr));
        AboutMenu->setTitle(QCoreApplication::translate("mainWindow", "\345\205\263\344\272\216", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("mainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
