#ifndef JUGADOR_H
#define JUGADOR_H

#include<QGraphicsRectItem>             //Para que mi jugador sea un rectangulo
#include<QGraphicsItem>                 //Necesito mostrarlo en escena
#include<QObject>                       //Para poder obtener y modificar parametros del rectangulo
#include<QMediaPlayer>

class Jugador: public QObject, public QGraphicsRectItem{
    Q_OBJECT                            // Macro para decir que la clase jugador es hijo de QObject y tiene todos los parámetros de QObject

public:
    Jugador(QGraphicsItem *parent = 0); //EL constructor por defecto asigna algo y evitamos posibles errores

    void keyPressEvent(QKeyEvent *e);   //Para leer pulsaciones del teclado
private:
    QMediaPlayer *STocaPacman;


};

#endif // JUGADOR_H
