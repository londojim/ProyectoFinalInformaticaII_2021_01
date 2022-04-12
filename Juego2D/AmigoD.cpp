#include<AmigoD.h>
#include<QGraphicsScene>
#include<Drogas.h>
#include<QDebug>

AmigoD::AmigoD(QGraphicsItem *parent)
{
    setRect(0,0,70,70);
}

void AmigoD::Disparar()
{
    Drogas *droga = new Drogas();
    droga->setPos(x(),y());  //Del centro de alto
    scene()->addItem(droga);
    //qDebug()<<"Se esta disparando";
}

void AmigoD::movAmigoD()
{

}
