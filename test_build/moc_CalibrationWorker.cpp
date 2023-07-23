/****************************************************************************
** Meta object code from reading C++ file 'CalibrationWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/CalibrationWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalibrationWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalibrationWorker_t {
    QByteArrayData data[17];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalibrationWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalibrationWorker_t qt_meta_stringdata_CalibrationWorker = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CalibrationWorker"
QT_MOC_LITERAL(1, 18, 17), // "newSequenceResult"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 45, 3), // "img"
QT_MOC_LITERAL(5, 49, 6), // "size_t"
QT_MOC_LITERAL(6, 56, 3), // "idx"
QT_MOC_LITERAL(7, 60, 7), // "success"
QT_MOC_LITERAL(8, 68, 10), // "logMessage"
QT_MOC_LITERAL(9, 79, 7), // "message"
QT_MOC_LITERAL(10, 87, 22), // "findPartialCirclesGrid"
QT_MOC_LITERAL(11, 110, 2), // "im"
QT_MOC_LITERAL(12, 113, 25), // "std::vector<cv::Point2f>&"
QT_MOC_LITERAL(13, 139, 1), // "q"
QT_MOC_LITERAL(14, 141, 25), // "std::vector<cv::Point3f>&"
QT_MOC_LITERAL(15, 167, 1), // "Q"
QT_MOC_LITERAL(16, 169, 13) // "circleSpacing"

    },
    "CalibrationWorker\0newSequenceResult\0"
    "\0cv::Mat\0img\0size_t\0idx\0success\0"
    "logMessage\0message\0findPartialCirclesGrid\0"
    "im\0std::vector<cv::Point2f>&\0q\0"
    "std::vector<cv::Point3f>&\0Q\0circleSpacing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalibrationWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       8,    1,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    4,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Bool,    4,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 12, 0x80000000 | 14, QMetaType::Float,   11,   13,   15,   16,

       0        // eod
};

void CalibrationWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalibrationWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newSequenceResult((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->findPartialCirclesGrid((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< std::vector<cv::Point2f>(*)>(_a[2])),(*reinterpret_cast< std::vector<cv::Point3f>(*)>(_a[3])),(*reinterpret_cast< const float(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CalibrationWorker::*)(const cv::Mat & , size_t , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrationWorker::newSequenceResult)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CalibrationWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrationWorker::logMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalibrationWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CalibrationWorker.data,
    qt_meta_data_CalibrationWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalibrationWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalibrationWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalibrationWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CalibrationWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CalibrationWorker::newSequenceResult(const cv::Mat & _t1, size_t _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CalibrationWorker::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
