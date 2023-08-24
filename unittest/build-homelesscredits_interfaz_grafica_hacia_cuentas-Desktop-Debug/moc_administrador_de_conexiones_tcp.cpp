/****************************************************************************
** Meta object code from reading C++ file 'administrador_de_conexiones_tcp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../homelesscredits_interfaz_grafica_hacia_cuentas/administrador_de_conexiones_tcp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'administrador_de_conexiones_tcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_administrador_de_conexiones_tcp_t {
    QByteArrayData data[3];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_administrador_de_conexiones_tcp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_administrador_de_conexiones_tcp_t qt_meta_stringdata_administrador_de_conexiones_tcp = {
    {
QT_MOC_LITERAL(0, 0, 31), // "administrador_de_conexiones_tcp"
QT_MOC_LITERAL(1, 32, 26), // "generar_la_primera_carpeta"
QT_MOC_LITERAL(2, 59, 0) // ""

    },
    "administrador_de_conexiones_tcp\0"
    "generar_la_primera_carpeta\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_administrador_de_conexiones_tcp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void administrador_de_conexiones_tcp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<administrador_de_conexiones_tcp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->generar_la_primera_carpeta(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (administrador_de_conexiones_tcp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&administrador_de_conexiones_tcp::generar_la_primera_carpeta)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject administrador_de_conexiones_tcp::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_administrador_de_conexiones_tcp.data,
    qt_meta_data_administrador_de_conexiones_tcp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *administrador_de_conexiones_tcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *administrador_de_conexiones_tcp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_administrador_de_conexiones_tcp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int administrador_de_conexiones_tcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void administrador_de_conexiones_tcp::generar_la_primera_carpeta()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
