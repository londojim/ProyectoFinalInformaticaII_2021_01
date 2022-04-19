#include<Asignaturas.h>
#include<QGraphicsScene>
#include<QTimer>
#include<math.h>
//# define M_PI           3.14159265358979323846
Asignaturas::Asignaturas(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/agenda.png"));
    //BArriba=1;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movAsignatura()));   //this por estar dentro de la misma clase
    timer->start(130);

}

void Asignaturas::movAsignatura()
{
    if(x()==85){
        anclajeY=230;
    }
    else if(x()==150){
        anclajeY=330;
    }else if(x()==200){
        anclajeY=310;
    } else if(x()==345){
        anclajeY=130;
    } else if(x()==350){
        anclajeY=130;
    } else if(x()==355){
        anclajeY=530;
    } else if(x()==550){
        anclajeY=230;
    }else if(x()==600){
        anclajeY=80;
    }
    //anclajeY=245;//_anclajeY;//300;
    fuerzaResorte = -k*(y()-anclajeY);
    fuerzasY=fuerzaResorte+masa*g;
    ay= fuerzasY/masa;
    vy=vy+ay*t;

    setPos(x(),y()+vy*t);

    /*
     if(BArriba==1){
        setPos(x(),y()+r*(cos(w*i)));//Mov hacia abajo
        BArriba=0;
    }
    else{
        setPos(x(),y()+r*-abs(cos(w*i)));//Mov hacia arriba
        BArriba=1;
    }*/
}
