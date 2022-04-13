#include<Distractor.h>
#include<QGraphicsScene>
#include<QTimer>
#include<cmath>
#include<QList>
#include<Jugador.h>
#include<Puntaje.h>
#include<Game.h>

extern Game *game;  //Llamamos una vble externa para interactuar con ella

Distractor::Distractor(QGraphicsItem *parent)
{
    setRect(0,0,70,70);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movDistractores()));   //this por estar dentro de la misma clase
    timer->start(30);
}

void Distractor::movDistractores()
{
    //int velx =0.5;
    //int vely=0.5;int dt=2;
    //setRotation(velx);

    /*
    double pi=3.1416;
    double Rad= 0.01745329252; //radianes
    int angulo=angulo*180/pi;
    int r=150;                          //radio de giro
    double W=-1;                    //velocidad angular
    double Desfase=0;
    double i=0;
    //int dt=2;
    i=i+Rad; //angulo de giro
    setPos(x()+r*cos(i*W+Desfase),y()+r*sin(i*W));
    */

    //setPos(x()+velx*dt+cos(30)+((dt*dt)/2),y()+vely*dt+sin(30)+((dt*dt)/2));
    //setPos(x()+velx*dt+((dt*dt)/2),y()+vely*dt+((dt*dt)/2));//Se van diagonal
    //setPos((x()+rect().width())/2+rect().width()*cos(3),(y()+rect().width())/2+rect().width()*sin(3));

    QList <QGraphicsItem *> colliding_items = collidingItems(); //Lista de QGraphicsItem.
    //Devuelve una lista de todos los elementos que están colisionando con la droga disparada

    for(int i=0, n=colliding_items.size(); i<n; i++ ){ //Mientras i<n: aumente i
        //Si colisiona con estudiante: la calificación baja
        if(typeid(  *(colliding_items[i])) == typeid(Jugador) ){//typeid retorna tipo de clase/objeto que estamos mirando
            game->nota->disminuir();

            //delete colliding_items[i];
            //delete this;
            return;

        }
    }


}

