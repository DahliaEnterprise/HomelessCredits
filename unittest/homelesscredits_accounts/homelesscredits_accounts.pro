QT -= gui
QT += network
CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bufer_de_un_mensaje.cpp \
        cabeza.cpp \
        el_coordinador_tcp.cpp \
        main.cpp \
        pila_de_transacciones_compiladas.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    bufer_de_un_mensaje.h \
    cabeza.h \
    el_coordinador_tcp.h \
    pila_de_transacciones_compiladas.h

