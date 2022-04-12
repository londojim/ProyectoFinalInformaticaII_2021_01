#include<Distractor.h>
#include<QGraphicsScene>
#include<Drogas.h>


Distractor::Distractor(QGraphicsItem *parent)
{
    setRect(0,0,70,70);
}

void Distractor::Disparar()
{
    Drogas *droga = new Drogas();
    droga->setPos(x()-5,y());
    scene()->addItem(droga);
}

void Distractor::movDistractores()
{

}

