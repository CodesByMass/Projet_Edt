/****************************************************************************
** Meta object code from reading C++ file 'fenetre_matiere.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "IG/Fenetres_ressources/fenetre_matiere.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre_matiere.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_fenetre_matiere_t {
    QByteArrayData data[6];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fenetre_matiere_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fenetre_matiere_t qt_meta_stringdata_fenetre_matiere = {
    {
QT_MOC_LITERAL(0, 0, 15), // "fenetre_matiere"
QT_MOC_LITERAL(1, 16, 9), // "actualise"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "Matiere*"
QT_MOC_LITERAL(4, 36, 1), // "g"
QT_MOC_LITERAL(5, 38, 13) // "creer_matiere"

    },
    "fenetre_matiere\0actualise\0\0Matiere*\0"
    "g\0creer_matiere"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fenetre_matiere[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void fenetre_matiere::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fenetre_matiere *_t = static_cast<fenetre_matiere *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actualise((*reinterpret_cast< Matiere*(*)>(_a[1]))); break;
        case 1: _t->creer_matiere(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (fenetre_matiere::*_t)(Matiere * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fenetre_matiere::actualise)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject fenetre_matiere::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fenetre_matiere.data,
      qt_meta_data_fenetre_matiere,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *fenetre_matiere::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fenetre_matiere::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_fenetre_matiere.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int fenetre_matiere::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void fenetre_matiere::actualise(Matiere * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
