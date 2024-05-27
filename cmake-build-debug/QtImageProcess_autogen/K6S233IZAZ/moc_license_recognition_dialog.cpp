/****************************************************************************
** Meta object code from reading C++ file 'license_recognition_dialog.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../headers/license_recognition_dialog.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'license_recognition_dialog.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS = QtMocHelpers::stringData(
    "LicenseRecognitionDialog",
    "mouse_clicked_in_view",
    "",
    "start_clicked",
    "next_clicked",
    "previous_clicked",
    "finish_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[25];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[13];
    char stringdata5[17];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS_t qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 24),  // "LicenseRecognitionDialog"
        QT_MOC_LITERAL(25, 21),  // "mouse_clicked_in_view"
        QT_MOC_LITERAL(47, 0),  // ""
        QT_MOC_LITERAL(48, 13),  // "start_clicked"
        QT_MOC_LITERAL(62, 12),  // "next_clicked"
        QT_MOC_LITERAL(75, 16),  // "previous_clicked"
        QT_MOC_LITERAL(92, 14)   // "finish_clicked"
    },
    "LicenseRecognitionDialog",
    "mouse_clicked_in_view",
    "",
    "start_clicked",
    "next_clicked",
    "previous_clicked",
    "finish_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLicenseRecognitionDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject LicenseRecognitionDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLicenseRecognitionDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LicenseRecognitionDialog, std::true_type>,
        // method 'mouse_clicked_in_view'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'next_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previous_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'finish_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LicenseRecognitionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LicenseRecognitionDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mouse_clicked_in_view(); break;
        case 1: _t->start_clicked(); break;
        case 2: _t->next_clicked(); break;
        case 3: _t->previous_clicked(); break;
        case 4: _t->finish_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *LicenseRecognitionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LicenseRecognitionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLicenseRecognitionDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::licence_recognition_dialog"))
        return static_cast< Ui::licence_recognition_dialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int LicenseRecognitionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
