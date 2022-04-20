#ifndef DROGAS_H
#define DROGAS_H

//#include <QGraphicsRectItem>    //Rectangulo que va en escena
#include<QGraphicsPixmapItem>
#include <QObject>
#include<QMediaPlayer>
#include<math.h>


class Drogas: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drogas();                   //Las drogas son disparadas por un objeto tipo distractor
public slots:
    void movDroga();     //Señal conectada al timer para tener un movimiento periodico
private:
    //QMediaPlayer *STocaDroga;
    float vx=-45;
    float vy=-40;
    float g=10;
    float t=1;
    float alfa=90;
};

#endif // DROGAS_H
