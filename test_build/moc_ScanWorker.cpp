/****************************************************************************
** Meta object code from reading C++ file 'ScanWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/ScanWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScanWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScanWorker_t {
    QByteArrayData data[16];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanWorker_t qt_meta_stringdata_ScanWorker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ScanWorker"
QT_MOC_LITERAL(1, 11, 13), // "showHistogram"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 34, 2), // "im"
QT_MOC_LITERAL(5, 37, 8), // "newFrame"
QT_MOC_LITERAL(6, 46, 5), // "frame"
QT_MOC_LITERAL(7, 52, 11), // "newFrameSeq"
QT_MOC_LITERAL(8, 64, 20), // "std::vector<cv::Mat>"
QT_MOC_LITERAL(9, 85, 8), // "frameSeq"
QT_MOC_LITERAL(10, 94, 10), // "logMessage"
QT_MOC_LITERAL(11, 105, 3), // "msg"
QT_MOC_LITERAL(12, 109, 8), // "finished"
QT_MOC_LITERAL(13, 118, 5), // "setup"
QT_MOC_LITERAL(14, 124, 6), // "doWork"
QT_MOC_LITERAL(15, 131, 11) // "stopWorking"

    },
    "ScanWorker\0showHistogram\0\0cv::Mat\0im\0"
    "newFrame\0frame\0newFrameSeq\0"
    "std::vector<cv::Mat>\0frameSeq\0logMessage\0"
    "msg\0finished\0setup\0doWork\0stopWorking"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       7,    1,   60,    2, 0x06 /* Public */,
      10,    1,   63,    2, 0x06 /* Public */,
      12,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   67,    2, 0x0a /* Public */,
      14,    0,   68,    2, 0x0a /* Public */,
      15,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScanWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScanWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showHistogram((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->newFrame((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->newFrameSeq((*reinterpret_cast< std::vector<cv::Mat>(*)>(_a[1]))); break;
        case 3: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->finished(); break;
        case 5: _t->setup(); break;
        case 6: _t->doWork(); break;
        case 7: _t->stopWorking(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScanWorker::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanWorker::showHistogram)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScanWorker::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanWorker::newFrame)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScanWorker::*)(std::vector<cv::Mat> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanWorker::newFrameSeq)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ScanWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanWorker::logMessage)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ScanWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanWorker::finished)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScanWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScanWorker.data,
    qt_meta_data_ScanWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScanWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScanWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScanWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ScanWorker::showHistogram(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScanWorker::newFrame(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScanWorker::newFrameSeq(std::vector<cv::Mat> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ScanWorker::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ScanWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
