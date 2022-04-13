#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QGraphicsTextItem>

class Puntaje:public QGraphicsTextItem{
public:
    Puntaje(QGraphicsItem * parent = 0);
    void disminuir();
    int getPuntaje();

private:
    int nota;

};
 #endif // PUNTAJE_H
