/****************************************************************************
** Meta object code from reading C++ file 'CalibrationDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/CalibrationDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalibrationDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalibrationDialog_t {
    QByteArrayData data[21];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalibrationDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalibrationDialog_t qt_meta_stringdata_CalibrationDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CalibrationDialog"
QT_MOC_LITERAL(1, 18, 19), // "newCalibrationSaved"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 15), // "CalibrationData"
QT_MOC_LITERAL(4, 55, 6), // "_calib"
QT_MOC_LITERAL(5, 62, 10), // "logMessage"
QT_MOC_LITERAL(6, 73, 3), // "msg"
QT_MOC_LITERAL(7, 77, 11), // "eventFilter"
QT_MOC_LITERAL(8, 89, 6), // "target"
QT_MOC_LITERAL(9, 96, 7), // "QEvent*"
QT_MOC_LITERAL(10, 104, 5), // "event"
QT_MOC_LITERAL(11, 110, 21), // "on_snapButton_clicked"
QT_MOC_LITERAL(12, 132, 26), // "on_calibrateButton_clicked"
QT_MOC_LITERAL(13, 159, 34), // "on_listWidget_itemSelectionCh..."
QT_MOC_LITERAL(14, 194, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(15, 216, 19), // "onNewSequenceResult"
QT_MOC_LITERAL(16, 236, 7), // "cv::Mat"
QT_MOC_LITERAL(17, 244, 3), // "img"
QT_MOC_LITERAL(18, 248, 6), // "size_t"
QT_MOC_LITERAL(19, 255, 3), // "idx"
QT_MOC_LITERAL(20, 259, 7) // "success"

    },
    "CalibrationDialog\0newCalibrationSaved\0"
    "\0CalibrationData\0_calib\0logMessage\0"
    "msg\0eventFilter\0target\0QEvent*\0event\0"
    "on_snapButton_clicked\0on_calibrateButton_clicked\0"
    "on_listWidget_itemSelectionChanged\0"
    "on_saveButton_clicked\0onNewSequenceResult\0"
    "cv::Mat\0img\0size_t\0idx\0success"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalibrationDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   60,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x08 /* Private */,
      12,    0,   66,    2, 0x08 /* Private */,
      13,    0,   67,    2, 0x08 /* Private */,
      14,    0,   68,    2, 0x08 /* Private */,
      15,    3,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 9,    8,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18, QMetaType::Bool,   17,   19,   20,

       0        // eod
};

void CalibrationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalibrationDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newCalibrationSaved((*reinterpret_cast< CalibrationData(*)>(_a[1]))); break;
        case 1: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_snapButton_clicked(); break;
        case 4: _t->on_calibrateButton_clicked(); break;
        case 5: _t->on_listWidget_itemSelectionChanged(); break;
        case 6: _t->on_saveButton_clicked(); break;
        case 7: _t->onNewSequenceResult((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< const size_t(*)>(_a[2])),(*reinterpret_cast< const bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CalibrationDialog::*)(CalibrationData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrationDialog::newCalibrationSaved)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CalibrationDialog::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrationDialog::logMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalibrationDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CalibrationDialog.data,
    qt_meta_data_CalibrationDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalibrationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalibrationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalibrationDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CalibrationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CalibrationDialog::newCalibrationSaved(CalibrationData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CalibrationDialog::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
