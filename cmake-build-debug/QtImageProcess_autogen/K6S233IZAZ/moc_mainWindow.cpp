/****************************************************************************
** Meta object code from reading C++ file 'mainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../headers/mainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSmainWindowENDCLASS = QtMocHelpers::stringData(
    "mainWindow",
    "actionSave_triggered",
    "",
    "on_spinBox_valueChanged",
    "value",
    "on_actionOpenFile_triggered",
    "on_actionRotate_triggered",
    "on_Generate_clicked",
    "on_actionHorizontalFlip_triggered",
    "on_actionVerticalFlip_triggered",
    "on_actionGray_triggered",
    "on_actionResize_triggered",
    "on_actionRestore_triggered",
    "on_actionQuit_triggered",
    "on_actionSaveOther_triggered",
    "on_actionHistogram_triggered",
    "on_actionAddNoise_triggered",
    "on_actionEdgeDetection_triggered",
    "on_actionLineDetection_triggered",
    "on_actionThresholdProcess_triggered",
    "on_actionFourier_triggered",
    "on_actionLowPassFilter_triggered",
    "on_actionHistogramEqualization_triggered",
    "on_actionMedianFilter_triggered",
    "on_actionGaussFilter_triggered",
    "on_actionLaplacianFilter_triggered",
    "on_actionSobelFilter_triggered",
    "on_actionDilation_triggered",
    "on_actionErosion_triggered",
    "on_actionOpening_triggered",
    "on_actionClosing_triggered",
    "on_LicenceRecognition_triggered",
    "on_actionColorPainting_triggered",
    "on_actionSketch_triggered",
    "on_actionOldPhoto_triggered"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmainWindowENDCLASS_t {
    uint offsetsAndSizes[70];
    char stringdata0[11];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[6];
    char stringdata5[28];
    char stringdata6[26];
    char stringdata7[20];
    char stringdata8[34];
    char stringdata9[32];
    char stringdata10[24];
    char stringdata11[26];
    char stringdata12[27];
    char stringdata13[24];
    char stringdata14[29];
    char stringdata15[29];
    char stringdata16[28];
    char stringdata17[33];
    char stringdata18[33];
    char stringdata19[36];
    char stringdata20[27];
    char stringdata21[33];
    char stringdata22[41];
    char stringdata23[32];
    char stringdata24[31];
    char stringdata25[35];
    char stringdata26[31];
    char stringdata27[28];
    char stringdata28[27];
    char stringdata29[27];
    char stringdata30[27];
    char stringdata31[32];
    char stringdata32[33];
    char stringdata33[26];
    char stringdata34[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmainWindowENDCLASS_t qt_meta_stringdata_CLASSmainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "mainWindow"
        QT_MOC_LITERAL(11, 20),  // "actionSave_triggered"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 23),  // "on_spinBox_valueChanged"
        QT_MOC_LITERAL(57, 5),  // "value"
        QT_MOC_LITERAL(63, 27),  // "on_actionOpenFile_triggered"
        QT_MOC_LITERAL(91, 25),  // "on_actionRotate_triggered"
        QT_MOC_LITERAL(117, 19),  // "on_Generate_clicked"
        QT_MOC_LITERAL(137, 33),  // "on_actionHorizontalFlip_trigg..."
        QT_MOC_LITERAL(171, 31),  // "on_actionVerticalFlip_triggered"
        QT_MOC_LITERAL(203, 23),  // "on_actionGray_triggered"
        QT_MOC_LITERAL(227, 25),  // "on_actionResize_triggered"
        QT_MOC_LITERAL(253, 26),  // "on_actionRestore_triggered"
        QT_MOC_LITERAL(280, 23),  // "on_actionQuit_triggered"
        QT_MOC_LITERAL(304, 28),  // "on_actionSaveOther_triggered"
        QT_MOC_LITERAL(333, 28),  // "on_actionHistogram_triggered"
        QT_MOC_LITERAL(362, 27),  // "on_actionAddNoise_triggered"
        QT_MOC_LITERAL(390, 32),  // "on_actionEdgeDetection_triggered"
        QT_MOC_LITERAL(423, 32),  // "on_actionLineDetection_triggered"
        QT_MOC_LITERAL(456, 35),  // "on_actionThresholdProcess_tri..."
        QT_MOC_LITERAL(492, 26),  // "on_actionFourier_triggered"
        QT_MOC_LITERAL(519, 32),  // "on_actionLowPassFilter_triggered"
        QT_MOC_LITERAL(552, 40),  // "on_actionHistogramEqualizatio..."
        QT_MOC_LITERAL(593, 31),  // "on_actionMedianFilter_triggered"
        QT_MOC_LITERAL(625, 30),  // "on_actionGaussFilter_triggered"
        QT_MOC_LITERAL(656, 34),  // "on_actionLaplacianFilter_trig..."
        QT_MOC_LITERAL(691, 30),  // "on_actionSobelFilter_triggered"
        QT_MOC_LITERAL(722, 27),  // "on_actionDilation_triggered"
        QT_MOC_LITERAL(750, 26),  // "on_actionErosion_triggered"
        QT_MOC_LITERAL(777, 26),  // "on_actionOpening_triggered"
        QT_MOC_LITERAL(804, 26),  // "on_actionClosing_triggered"
        QT_MOC_LITERAL(831, 31),  // "on_LicenceRecognition_triggered"
        QT_MOC_LITERAL(863, 32),  // "on_actionColorPainting_triggered"
        QT_MOC_LITERAL(896, 25),  // "on_actionSketch_triggered"
        QT_MOC_LITERAL(922, 27)   // "on_actionOldPhoto_triggered"
    },
    "mainWindow",
    "actionSave_triggered",
    "",
    "on_spinBox_valueChanged",
    "value",
    "on_actionOpenFile_triggered",
    "on_actionRotate_triggered",
    "on_Generate_clicked",
    "on_actionHorizontalFlip_triggered",
    "on_actionVerticalFlip_triggered",
    "on_actionGray_triggered",
    "on_actionResize_triggered",
    "on_actionRestore_triggered",
    "on_actionQuit_triggered",
    "on_actionSaveOther_triggered",
    "on_actionHistogram_triggered",
    "on_actionAddNoise_triggered",
    "on_actionEdgeDetection_triggered",
    "on_actionLineDetection_triggered",
    "on_actionThresholdProcess_triggered",
    "on_actionFourier_triggered",
    "on_actionLowPassFilter_triggered",
    "on_actionHistogramEqualization_triggered",
    "on_actionMedianFilter_triggered",
    "on_actionGaussFilter_triggered",
    "on_actionLaplacianFilter_triggered",
    "on_actionSobelFilter_triggered",
    "on_actionDilation_triggered",
    "on_actionErosion_triggered",
    "on_actionOpening_triggered",
    "on_actionClosing_triggered",
    "on_LicenceRecognition_triggered",
    "on_actionColorPainting_triggered",
    "on_actionSketch_triggered",
    "on_actionOldPhoto_triggered"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  206,    2, 0x08,    1 /* Private */,
       3,    1,  207,    2, 0x08,    2 /* Private */,
       5,    0,  210,    2, 0x08,    4 /* Private */,
       6,    0,  211,    2, 0x08,    5 /* Private */,
       7,    0,  212,    2, 0x08,    6 /* Private */,
       8,    0,  213,    2, 0x08,    7 /* Private */,
       9,    0,  214,    2, 0x08,    8 /* Private */,
      10,    0,  215,    2, 0x08,    9 /* Private */,
      11,    0,  216,    2, 0x08,   10 /* Private */,
      12,    0,  217,    2, 0x08,   11 /* Private */,
      13,    0,  218,    2, 0x08,   12 /* Private */,
      14,    0,  219,    2, 0x08,   13 /* Private */,
      15,    0,  220,    2, 0x08,   14 /* Private */,
      16,    0,  221,    2, 0x08,   15 /* Private */,
      17,    0,  222,    2, 0x08,   16 /* Private */,
      18,    0,  223,    2, 0x08,   17 /* Private */,
      19,    0,  224,    2, 0x08,   18 /* Private */,
      20,    0,  225,    2, 0x08,   19 /* Private */,
      21,    0,  226,    2, 0x08,   20 /* Private */,
      22,    0,  227,    2, 0x08,   21 /* Private */,
      23,    0,  228,    2, 0x08,   22 /* Private */,
      24,    0,  229,    2, 0x08,   23 /* Private */,
      25,    0,  230,    2, 0x08,   24 /* Private */,
      26,    0,  231,    2, 0x08,   25 /* Private */,
      27,    0,  232,    2, 0x08,   26 /* Private */,
      28,    0,  233,    2, 0x08,   27 /* Private */,
      29,    0,  234,    2, 0x08,   28 /* Private */,
      30,    0,  235,    2, 0x08,   29 /* Private */,
      31,    0,  236,    2, 0x08,   30 /* Private */,
      32,    0,  237,    2, 0x08,   31 /* Private */,
      33,    0,  238,    2, 0x08,   32 /* Private */,
      34,    0,  239,    2, 0x08,   33 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject mainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSmainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mainWindow, std::true_type>,
        // method 'actionSave_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_actionOpenFile_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRotate_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Generate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionHorizontalFlip_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionVerticalFlip_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionGray_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionResize_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRestore_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionQuit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSaveOther_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionHistogram_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAddNoise_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEdgeDetection_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLineDetection_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionThresholdProcess_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFourier_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLowPassFilter_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionHistogramEqualization_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionMedianFilter_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionGaussFilter_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLaplacianFilter_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSobelFilter_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionDilation_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionErosion_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOpening_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionClosing_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_LicenceRecognition_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionColorPainting_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSketch_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOldPhoto_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void mainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->actionSave_triggered(); break;
        case 1: _t->on_spinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_actionOpenFile_triggered(); break;
        case 3: _t->on_actionRotate_triggered(); break;
        case 4: _t->on_Generate_clicked(); break;
        case 5: _t->on_actionHorizontalFlip_triggered(); break;
        case 6: _t->on_actionVerticalFlip_triggered(); break;
        case 7: _t->on_actionGray_triggered(); break;
        case 8: _t->on_actionResize_triggered(); break;
        case 9: _t->on_actionRestore_triggered(); break;
        case 10: _t->on_actionQuit_triggered(); break;
        case 11: _t->on_actionSaveOther_triggered(); break;
        case 12: _t->on_actionHistogram_triggered(); break;
        case 13: _t->on_actionAddNoise_triggered(); break;
        case 14: _t->on_actionEdgeDetection_triggered(); break;
        case 15: _t->on_actionLineDetection_triggered(); break;
        case 16: _t->on_actionThresholdProcess_triggered(); break;
        case 17: _t->on_actionFourier_triggered(); break;
        case 18: _t->on_actionLowPassFilter_triggered(); break;
        case 19: _t->on_actionHistogramEqualization_triggered(); break;
        case 20: _t->on_actionMedianFilter_triggered(); break;
        case 21: _t->on_actionGaussFilter_triggered(); break;
        case 22: _t->on_actionLaplacianFilter_triggered(); break;
        case 23: _t->on_actionSobelFilter_triggered(); break;
        case 24: _t->on_actionDilation_triggered(); break;
        case 25: _t->on_actionErosion_triggered(); break;
        case 26: _t->on_actionOpening_triggered(); break;
        case 27: _t->on_actionClosing_triggered(); break;
        case 28: _t->on_LicenceRecognition_triggered(); break;
        case 29: _t->on_actionColorPainting_triggered(); break;
        case 30: _t->on_actionSketch_triggered(); break;
        case 31: _t->on_actionOldPhoto_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject *mainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::mainWindow"))
        return static_cast< Ui::mainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
