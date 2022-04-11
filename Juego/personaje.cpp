#include "personaje.h"
#define rutaS "../PROYECTO FINAL/Imagenes/estudianteM.png"

Personaje::Personaje()
{

}

Personaje::~Personaje()
{

}

QRectF Personaje::boundingRect() const
{
    return QRectF(0,0,20,20);

}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        //painter->setBrush(Qt::green);
        //painter->drawRect(boundingRect());

        QPixmap pxmap(rutaS);
        painter->drawPixmap(boundingRect(),pxmap,pxmap.rect());

}
