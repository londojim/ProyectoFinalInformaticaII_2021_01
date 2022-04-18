#include<Asignaturas.h>
#include<QGraphicsScene>
#include<QTimer>
#include<math.h>
# define M_PI           3.14159265358979323846
Asignaturas::Asignaturas(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/agenda.png"));
    BArriba=1;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movAsignatura()));   //this por estar dentro de la misma clase
    timer->start(130);

    float vx, vy;
    float ax, ay;
    float g;
    int masa;
    int k;



}

void Asignaturas::movAsignatura()
{
    double w=0.5; //V ANGULAR
    float r=5; //RADIO DE GIRO
    double i=i+rad;//ANGULO DE GIRO EN RAD

    anchorx=10; anchory=300;
    int fuerza = (-k*(y()-anchory))+masa*g;
    ay= fuerza/masa;
    vy=vy+ay*0.28;

    setPos(x(),y()+vy*0.28);//Mov hacia abajo
    //setPos(x(),y()+r*(cos(w*i+(M_PI/2))));//Mov hacia abajo

    /*    float vx, vy;
    float ax, ay;
    float g;
    int masa;
    int k;
    int anchory, anchorx;*/
    /*
     * if(BArriba==1){
        setPos(x(),y()+r*(cos(w*i)));//Mov hacia abajo
        BArriba=0;
    }
    else{
        setPos(x(),y()+r*-abs(cos(w*i)));//Mov hacia arriba
        BArriba=1;
    }*/
}
