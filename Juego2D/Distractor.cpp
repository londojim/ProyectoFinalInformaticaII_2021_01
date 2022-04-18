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
    vel=4; radio =1;
    static float degrees= 0.0f;
    float radians = qDegreesToRadians(degrees);
    degrees+=vel; //velocidad
    setPos(x()+radio*qCos(radians) , y()+radio*qSin(radians));

 }

