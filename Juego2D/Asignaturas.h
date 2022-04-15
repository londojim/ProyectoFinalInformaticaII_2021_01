#ifndef ASIGNATURAS_H
#define ASIGNATURAS_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include <QObject>

class Asignaturas: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Asignaturas(QGraphicsItem *parent = 0);
public slots:
    void movAsignatura();     //Señal conectada al timer para tener un movimiento periodico
private:
    bool BArriba;
};

#endif // ASIGNATURAS_H
