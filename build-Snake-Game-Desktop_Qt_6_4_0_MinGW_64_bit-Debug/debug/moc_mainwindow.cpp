/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Snake-Game/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[6];
    char stringdata5[27];
    char stringdata6[27];
    char stringdata7[29];
    char stringdata8[22];
    char stringdata9[22];
    char stringdata10[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 5),  // "logic"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 5),  // "stop1"
        QT_MOC_LITERAL(24, 5),  // "stop2"
        QT_MOC_LITERAL(30, 26),  // "on_difficulty_slug_clicked"
        QT_MOC_LITERAL(57, 26),  // "on_difficulty_worm_clicked"
        QT_MOC_LITERAL(84, 28),  // "on_difficulty_python_clicked"
        QT_MOC_LITERAL(113, 21),  // "on_one_player_clicked"
        QT_MOC_LITERAL(135, 21),  // "on_two_player_clicked"
        QT_MOC_LITERAL(157, 21)   // "on_start_game_clicked"
    },
    "MainWindow",
    "logic",
    "",
    "stop1",
    "stop2",
    "on_difficulty_slug_clicked",
    "on_difficulty_worm_clicked",
    "on_difficulty_python_clicked",
    "on_one_player_clicked",
    "on_two_player_clicked",
    "on_start_game_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    0,   69,    2, 0x0a,    2 /* Public */,
       4,    0,   70,    2, 0x0a,    3 /* Public */,
       5,    0,   71,    2, 0x0a,    4 /* Public */,
       6,    0,   72,    2, 0x0a,    5 /* Public */,
       7,    0,   73,    2, 0x0a,    6 /* Public */,
       8,    0,   74,    2, 0x0a,    7 /* Public */,
       9,    0,   75,    2, 0x0a,    8 /* Public */,
      10,    0,   76,    2, 0x0a,    9 /* Public */,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'logic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_difficulty_slug_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_difficulty_worm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_difficulty_python_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_one_player_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_two_player_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_start_game_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logic(); break;
        case 1: _t->stop1(); break;
        case 2: _t->stop2(); break;
        case 3: _t->on_difficulty_slug_clicked(); break;
        case 4: _t->on_difficulty_worm_clicked(); break;
        case 5: _t->on_difficulty_python_clicked(); break;
        case 6: _t->on_one_player_clicked(); break;
        case 7: _t->on_two_player_clicked(); break;
        case 8: _t->on_start_game_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
