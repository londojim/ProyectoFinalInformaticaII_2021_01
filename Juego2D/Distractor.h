#ifndef DISTRACTOR_H
#define DISTRACTOR_H

#include<QGraphicsRectItem>         //El distractor es un rectangulo. Luego se pinta con el sprite
#include<QGraphicsItem>             //Necesito mostrarlo en escena
#include<QObject>                   //Para poder obtener y modificar parametros del rectangulo
#include <math.h>

class Distractor: public QObject, public QGraphicsRectItem{
    Q_OBJECT                        // Macro para decir que la clase jugador es hijo de QObject y tiene todos los parámetros de QObject

public:
    Distractor(QGraphicsItem *parent = 0); //EL constructor por defecto asigna algo y evitamos posibles errores

public slots:
    void movDistractores();
};

#endif // DISTRACTOR_H
