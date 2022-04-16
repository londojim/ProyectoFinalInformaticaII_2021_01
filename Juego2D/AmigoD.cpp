#include<AmigoD.h>
#include<QGraphicsScene>
#include<Drogas.h>
#include<QDebug>

AmigoD::AmigoD(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    SDroga = new QMediaPlayer();
    SDroga->setMedia(QUrl("qrc:/s/lanzamientoDroga.mp3"));

    setPixmap(QPixmap(":/imagenes/Amigo.png"));
    }

void AmigoD::Disparar()
{
    Drogas *droga = new Drogas();
    SDroga->play();

    droga->setPos(x()+15,y()+40);  //Del centro de alto
    scene()->addItem(droga);

    //qDebug()<<"Se esta disparando";
}

void AmigoD::movAmigoD()
{

}
