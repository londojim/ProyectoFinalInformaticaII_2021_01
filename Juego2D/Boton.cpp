#include "Boton.h"
#include <QBrush>
#include <QGraphicsTextItem>

Boton::Boton(QString nombreB, QGraphicsItem *parent)
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    text = new QGraphicsTextItem(nombreB,this);
    //el texto dentro del botón está: boton-(long texto/2)
    int xPos = rect().width()/2 -text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // habilitar evento hover
    setAcceptHoverEvents(true);
}

void Boton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit click();
}

void Boton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{   //dibujamos el boton cuando estamos encima
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Boton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{   //dibujamos el boton cuando no estamos encima
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
