#include<Drogas.h>
#include<QGraphicsScene>
#include<QTimer>
#include<QtDebug>
#include<QList>
#include<Jugador.h>
#include<Game.h>

#include<QMediaPlayer>
#include<QBrush>
#include<QImage>

extern Game *game;

Drogas::Drogas()
{
    //Dibujar la droga que será disparada por un objeto tipo distractor
    //setRect(0,0,35,40); //Damos posicion el origen y un tamaño
    setPixmap(QPixmap(":/imagenes/drogas.png"));    //Creamos la señal para poder conectar el timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movDroga()));  //La funcion que conectamos se va a ejecutar en cada flaco de reloj del sistema
    timer->start(80);  //En milisegundos

}

void Drogas::movDroga()
{
    QList <QGraphicsItem *> colliding_items = collidingItems(); //Lista de QGraphicsItem.
    //Devuelve una lista de todos los elementos que están colisionando con la droga disparada

    for(int i=0, n=colliding_items.size(); i<n; i++ ){ //Mientras i<n: aumente i
        //Si colisiona con estudiante: Reprueba inmediatamente.

        if(typeid(  *(colliding_items[i])) == typeid(Jugador) ){//typeid retorna tipo de clase/objeto que estamos mirando
            STocaDroga= new QMediaPlayer();
            STocaDroga->setMedia(QUrl("qrc:/s/TocaDroga.mp3"));
            STocaDroga->play();
            //delete colliding_items[i];
            //delete this;
            game->GameOver();
            return ;
        }
    }

    setPos(x()-10,y());             //Por la ubicación del amigo, la droga irá a la  izquierda
    if(pos().x()+pixmap().width()<0)  //Eliminar la droga cuando sale de la escena
    {
        scene()->removeItem(this);
        delete this;
    }
}
