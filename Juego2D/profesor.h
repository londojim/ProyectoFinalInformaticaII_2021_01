#ifndef PROFESOR_H
#define PROFESOR_H



#include<QGraphicsPixmapItem>
#include<QGraphicsItem>             //Necesito mostrarlo en escena
#include<QObject>                   //Para poder obtener y modificar parametros del rectangulo
#include<QMediaPlayer>

class Profesor: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Profesor(QGraphicsItem *parent = 0);
public slots:
    //void movProfesor();
private:
    QMediaPlayer *SDroga;
};

#endif // PROFESOR_H
