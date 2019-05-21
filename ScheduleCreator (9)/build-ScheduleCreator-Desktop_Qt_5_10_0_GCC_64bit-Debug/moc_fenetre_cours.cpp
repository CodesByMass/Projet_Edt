/****************************************************************************
** Meta object code from reading C++ file 'fenetre_cours.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ScheduleCreator/IG/Fenetres_ressources/fenetre_cours.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre_cours.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Fenetre_cours_t {
    QByteArrayData data[8];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Fenetre_cours_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Fenetre_cours_t qt_meta_stringdata_Fenetre_cours = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Fenetre_cours"
QT_MOC_LITERAL(1, 14, 15), // "actualiseOnglet"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "Cours*"
QT_MOC_LITERAL(4, 38, 1), // "c"
QT_MOC_LITERAL(5, 40, 11), // "creer_Cours"
QT_MOC_LITERAL(6, 52, 17), // "actualiser_listes"
QT_MOC_LITERAL(7, 70, 16) // "matiere_actuelle"

    },
    "Fenetre_cours\0actualiseOnglet\0\0Cours*\0"
    "c\0creer_Cours\0actualiser_listes\0"
    "matiere_actuelle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fenetre_cours[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x0a /* Public */,
       6,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void Fenetre_cours::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Fenetre_cours *_t = static_cast<Fenetre_cours *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actualiseOnglet((*reinterpret_cast< Cours*(*)>(_a[1]))); break;
        case 1: _t->creer_Cours(); break;
        case 2: _t->actualiser_listes((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Fenetre_cours::*_t)(Cours * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Fenetre_cours::actualiseOnglet)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Fenetre_cours::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Fenetre_cours.data,
      qt_meta_data_Fenetre_cours,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Fenetre_cours::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fenetre_cours::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Fenetre_cours.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Fenetre_cours::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Fenetre_cours::actualiseOnglet(Cours * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
