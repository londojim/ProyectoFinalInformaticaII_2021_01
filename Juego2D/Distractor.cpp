#include<Distractor.h>
#include<QGraphicsScene>
#include<QTimer>
#include<cmath>

Distractor::Distractor(QGraphicsItem *parent)
{
    setRect(0,0,70,70);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movDistractores()));   //this por estar dentro de la misma clase
    timer->start(30);
}

void Distractor::movDistractores()
{
    int velx=0.5;int vely=0.5;int dt=2;

    setPos(x()+velx*dt+cos(30)+((dt*dt)/2),y()+vely*dt+sin(30)+((dt*dt)/2));
    //setPos(x()+velx*dt+((dt*dt)/2),y()+vely*dt+((dt*dt)/2));//Se van diagonal
    //setPos((x()+rect().width())/2+rect().width()*cos(3),(y()+rect().width())/2+rect().width()*sin(3));
}

