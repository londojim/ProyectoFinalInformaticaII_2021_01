#include "profesor.h"
#include<QGraphicsScene>

Profesor::Profesor(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("qrc:/i/profe.png"));
    SDroga = new QMediaPlayer();
    setPixmap(QPixmap(":/imagenes/Amigo.png"));
    }

//void movProfesor(){}
