#ifndef ASIGNATURAS_H
#define ASIGNATURAS_H

#include <QGraphicsRectItem>    //Rectangulo que va en escena
#include <QObject>

class Asignaturas: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Asignaturas(QGraphicsItem *parent = 0);
public slots:
    void movAsignatura();     //Señal conectada al timer para tener un movimiento periodico

};

#endif // ASIGNATURAS_H
