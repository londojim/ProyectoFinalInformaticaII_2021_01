#include<Distractor.h>
#include<QGraphicsScene>
#include<QTimer>
#include<cmath>
#include<QList>
#include<Jugador.h>
#include<Puntaje.h>
#include <QtMath>
#include<Game.h>

extern Game *game;  //Llamamos una vble externa para interactuar con ella
extern Jugador *estudiante;

Distractor::Distractor(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/Consola.png"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movDistractores()));   //this por estar dentro de la misma clase
    timer->start(100);

}

void Distractor::movDistractores()
{
    vel=4; radio =8;
    static float degrees= 0.0f; //sin esto se me va en linea recta.verificar xq
    float radians = qDegreesToRadians(degrees);
    degrees+=vel; //velocidad
    setPos(x()+radio*qCos(radians) , y()+radio*qSin(radians));

    QList <QGraphicsItem *> colliding_items = collidingItems(); //Lista de QGraphicsItem.
    //Devuelve una lista de todos los elementos que están colisionando con la droga disparada
    for(int i=0, n=colliding_items.size(); i<n; i++ ){ //Mientras i<n: aumente i
        //Si colisiona con estudiante: la calificación baja
        if(typeid(  *(colliding_items[i])) == typeid(Jugador) ){//typeid retorna tipo de clase/objeto que estamos mirando
            STocaPacman= new QMediaPlayer();
            STocaPacman->setMedia(QUrl("qrc:/s/TocaPacman.mp3"));
            STocaPacman->play();
            game->nota->disminuir();
            game->estudiante->setPos(10,y()); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            return ;
        }
    }
}
