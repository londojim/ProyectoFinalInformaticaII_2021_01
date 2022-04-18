#ifndef DISTRACTOR_H
#define DISTRACTOR_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>             //Necesito mostrarlo en escena
#include<QObject>                   //Para poder obtener y modificar parametros del rectangulo
#include <math.h>
#include <QtMath>

class Distractor: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT                        // Macro para decir que la clase jugador es hijo de QObject y tiene todos los parámetros de QObject

public:
    Distractor(QGraphicsItem *parent = 0); //EL constructor por defecto asigna algo y evitamos posibles errores
    float radio;
    float vel;

    float radians = 0;
public slots:
    void movDistractores();

};

#endif // DISTRACTOR_H
