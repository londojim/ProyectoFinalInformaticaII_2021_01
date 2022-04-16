#include "profesor.h"
#include<QGraphicsScene>

Profesor::Profesor(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("qrc:/imagenes/profe.png"));

    }

//void movProfesor(){}
