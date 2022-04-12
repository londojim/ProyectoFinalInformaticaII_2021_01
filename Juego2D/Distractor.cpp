#include<Distractor.h>
#include<QGraphicsScene>
#include<Drogas.h>


Distractor::Distractor(QGraphicsItem *parent)
{

}

void Distractor::Disparar()
{
    Drogas *droga = new Drogas();
    droga->setPos(x()-5,y());
    scene()->addItem(droga);
}

