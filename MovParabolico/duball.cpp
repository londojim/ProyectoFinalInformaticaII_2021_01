#include "duball.h"
//#include "qgraphicsscene.h"
#include<QPainter>



double DuBall::pos_x() const
{
    return m_pos_x;
}

void DuBall::setPos_x(double newPos_x)
{
    m_pos_x = newPos_x;
}

double DuBall::pos_y() const
{
    return m_pos_y;
}

void DuBall::setPos_y(double newPos_y)
{
    m_pos_y = newPos_y;
}

double DuBall::width() const
{
    return m_width;
}

void DuBall::setWidth(double newWidth)
{
    m_width = newWidth;
}

double DuBall::height() const
{
    return m_height;
}

void DuBall::setHeight(double newHeight)
{
    m_height = newHeight;
}

QRectF DuBall::boundingRect() const
{
    return QRectF(m_pos_x-m_width,m_pos_y-m_height,m_width*2.0,m_height*2.0 );
}

void DuBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget) {
  (void)option;//para deshabilitar la variable option
  (void)widget;//para  deshabilitar la variable widget
    painter->setBrush(Qt::red);//se rellena de color rojo el interior de la figura
    painter->drawEllipse( QPointF(m_pos_x,m_pos_y),m_width,m_height);
    //painter->setBrush(Qt::NoBrush);//para que el rectangulo no se pinte con relleno
    //painter->drawRect(boundingRect());//Crea el rectangulo circunscrito al circulo
}

DuBall::DuBall(double x, double y, double w, double h, QGraphicsItem *parent)
    :QGraphicsItem(parent)
{
    m_pos_x = x;
    m_pos_y = y;
    m_width = w;
    m_height = h;
}
