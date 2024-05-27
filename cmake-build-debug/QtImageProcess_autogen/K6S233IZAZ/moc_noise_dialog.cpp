/****************************************************************************
** Meta object code from reading C++ file 'noise_dialog.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../headers/noise_dialog.hpp"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'noise_dialog.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSNoiseDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNoiseDialogENDCLASS = QtMocHelpers::stringData(
    "NoiseDialog",
    "mouse_clicked_in_src",
    "",
    "salt_noise_checked",
    "button_clicked",
    "gaussian_noise_checked",
    "speckle_noise_checked",
    "save_triggered"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNoiseDialogENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[12];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[15];
    char stringdata5[23];
    char stringdata6[22];
    char stringdata7[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNoiseDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNoiseDialogENDCLASS_t qt_meta_stringdata_CLASSNoiseDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "NoiseDialog"
        QT_MOC_LITERAL(12, 20),  // "mouse_clicked_in_src"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 18),  // "salt_noise_checked"
        QT_MOC_LITERAL(53, 14),  // "button_clicked"
        QT_MOC_LITERAL(68, 22),  // "gaussian_noise_checked"
        QT_MOC_LITERAL(91, 21),  // "speckle_noise_checked"
        QT_MOC_LITERAL(113, 14)   // "save_triggered"
    },
    "NoiseDialog",
    "mouse_clicked_in_src",
    "",
    "salt_noise_checked",
    "button_clicked",
    "gaussian_noise_checked",
    "speckle_noise_checked",
    "save_triggered"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNoiseDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject NoiseDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSNoiseDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNoiseDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNoiseDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NoiseDialog, std::true_type>,
        // method 'mouse_clicked_in_src'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'salt_noise_checked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gaussian_noise_checked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'speckle_noise_checked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'save_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NoiseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NoiseDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mouse_clicked_in_src(); break;
        case 1: _t->salt_noise_checked(); break;
        case 2: _t->button_clicked(); break;
        case 3: _t->gaussian_noise_checked(); break;
        case 4: _t->speckle_noise_checked(); break;
        case 5: _t->save_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *NoiseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoiseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNoiseDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::add_noise_dialog"))
        return static_cast< Ui::add_noise_dialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int NoiseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
