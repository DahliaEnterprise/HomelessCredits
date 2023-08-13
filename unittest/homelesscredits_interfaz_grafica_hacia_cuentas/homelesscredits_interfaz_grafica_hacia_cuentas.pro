QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrador_de_conexiones_tcp.cpp \
    diseno_de_estado_de_conexion.cpp \
    main.cpp \
    solo_ventana.cpp \
    solo_ventana_lista_de_botones.cpp

HEADERS += \
    administrador_de_conexiones_tcp.h \
    diseno_de_estado_de_conexion.h \
    solo_ventana.h \
    solo_ventana_lista_de_botones.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
