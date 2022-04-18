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
    float vx; float vy=0;
    float ax, ay;
    float g=0.1;
    int masa=1;
    int k=4;
    float anchory, anchorx;

    double rad=1;
    int i =0;

};

#endif // ASIGNATURAS_H
