#include<Distractor.h>
#include<QGraphicsScene>
#include<QTimer>
#include<cmath>

Distractor::Distractor(QGraphicsItem *parent)
{
    setRect(0,0,70,70);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movDistractores()));   //this por estar dentro de la misma clase
    timer->start(130);
}

void Distractor::movDistractores()
{
    setPos((x()+rect().width())/2+rect().width()*cos(3),(y()+rect().width())/2+rect().width()*sin(3));
}

