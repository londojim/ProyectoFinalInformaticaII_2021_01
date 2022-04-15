#ifndef AMIGOD_H
#define AMIGOD_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>             //Necesito mostrarlo en escena
#include<QObject>                   //Para poder obtener y modificar parametros del rectangulo
#include<QMediaPlayer>

class AmigoD: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT                        // Macro para decir que la clase jugador es hijo de QObject y tiene todos los parámetros de QObject

public:
    AmigoD(QGraphicsItem *parent = 0); //EL constructor por defecto asigna algo y evitamos posibles errores

public slots:
    void movAmigoD();
    void Disparar();
private:
    QMediaPlayer *SDroga;
};
#endif // AMIGOD_H
