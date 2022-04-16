#include<Asignaturas.h>
#include<QGraphicsScene>
#include<QTimer>
#include<math.h>
Asignaturas::Asignaturas(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/agenda.png"));
    BArriba=1;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movAsignatura()));   //this por estar dentro de la misma clase
    timer->start(130);
}

void Asignaturas::movAsignatura()
{
    double w=0.5; //V ANGULAR
    int r=30; //RADIO DE GIRO
    double rad=0.01745329252;
    double i=i+rad;//ANGULO DE GIRO EN RAD

    if(BArriba==1){
        setPos(x(),y()+r*(cos(w*i)));//Mov hacia abajo
        //setPos(x(),y()+20);
        BArriba=0;    }
    else{
        setPos(x(),y()+r*-abs(cos(w*i)));//Mov hacia arriba
        //setPos(x(),y()-20);
        BArriba=1;
    }
}
