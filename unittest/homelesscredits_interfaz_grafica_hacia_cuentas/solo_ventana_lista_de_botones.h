#ifndef SOLO_VENTANA_LISTA_DE_BOTONES_H
#define SOLO_VENTANA_LISTA_DE_BOTONES_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QDebug>

class solo_ventana_lista_de_botones : public QWidget
{
    Q_OBJECT
public:
    explicit solo_ventana_lista_de_botones(QWidget *parent = nullptr);
    void inicializar();

private:
    QBoxLayout * layout;
    QPushButton * boton_conectar;
    QPushButton * boton_generar_clave;

signals:
    void button_has_been_pressed(QString titulo_de_boton);
private slots:
    void pressed_conectar();
    void pressed_generar_clave();
};

#endif // SOLO_VENTANA_LISTA_DE_BOTONES_H
