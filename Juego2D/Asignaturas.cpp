#include<Asignaturas.h>
#include<QGraphicsScene>
#include<QTimer>

Asignaturas::Asignaturas(QGraphicsItem *parent)
{
    setRect(0,0,70,70);
    BArriba=1;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movAsignatura()));   //this por estar dentro de la misma clase
    timer->start(130);
}

void Asignaturas::movAsignatura()
{
    if(BArriba==1){
        setPos(x(),y()+20); //Mov hacia abajo
        BArriba=0;    }
    else{
        setPos(x(),y()-20); //Mov hacia arriba
        BArriba=1;
    }
}
