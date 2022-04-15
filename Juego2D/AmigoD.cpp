#include<AmigoD.h>
#include<QGraphicsScene>
#include<Drogas.h>
#include<QDebug>

AmigoD::AmigoD(QGraphicsItem *parent)
{
    setRect(0,0,85,85);
        SDroga = new QMediaPlayer();
        SDroga->setMedia(QUrl("qrc:/s/lanzamientoDroga.mp3"));
    }

void AmigoD::Disparar()
{
    Drogas *droga = new Drogas();
    SDroga->play();

    droga->setPos(x(),y());  //Del centro de alto
    scene()->addItem(droga);
    //qDebug()<<"Se esta disparando";
}

void AmigoD::movAmigoD()
{

}
