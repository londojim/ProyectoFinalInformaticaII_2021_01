#include<AmigoD.h>
#include<QGraphicsScene>
#include<Drogas.h>
#include<QDebug>

AmigoD::AmigoD(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("qrc:/i/drogas.png"));
    SDroga = new QMediaPlayer();
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
