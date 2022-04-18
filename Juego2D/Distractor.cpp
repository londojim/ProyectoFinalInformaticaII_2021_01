#include<Distractor.h>
#include<QGraphicsScene>
#include<QTimer>
#include<cmath>
#include<QList>
#include<Jugador.h>
#include<Puntaje.h>
#include <QtMath>

Distractor::Distractor(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/Consola.png"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movDistractores()));   //this por estar dentro de la misma clase
    timer->start(30);

}

void Distractor::movDistractores()
{
    vel=0.4; radio =15;
    static float degrees= 0.0f;
    float radians = qDegreesToRadians(degrees);
    degrees+=vel; //velocidad
    setPos(x()+radio*qCos(radians) , y()+radio*qSin(radians));

    /*
    //int velx =0.5;
    //int vely=0.5;int dt=2;
    //setRotation(velx);

    //int angulo=angulo*180/pi;

    int r=3;                   //radio de giro
    double W=-1;                //velocidad angular
    double Desfase=-3.01416;
    double rad=0.01745329252;
            int i=i+rad;//ANGULO DE GIRO EN RAD

    //setPos(x()+r*cos(i*W+Desfase),y()+r*sin(i*W));


    //setPos(x()+velx*dt+cos(30)+((dt*dt)/2),y()+vely*dt+sin(30)+((dt*dt)/2));
    //setPos(x()+velx*dt+((dt*dt)/2),y()+vely*dt+((dt*dt)/2));//Se van diagonal
    //setPos((x()+rect().width())/2+rect().width()*cos(3),(y()+rect().width())/2+rect().width()*sin(3));
*/



}

