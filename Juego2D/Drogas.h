#ifndef DROGAS_H
#define DROGAS_H

#include <QGraphicsRectItem>    //Rectangulo que va en escena
#include <QObject>

class Drogas: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Drogas();   //Las drogas son disparadas por un objeto tipo distractor
    void movimientoDroga();  //Señal conectada al timer para tener un movimiento periodico

};

#endif // DROGAS_H
