#include<Jugador.h>
#include<QGraphicsScene>
#include<QKeyEvent>         //Para que reconozca pulsaciones del teclado
#include<Game.h>
extern Game *game;  //Llamamos una vble externa para interactuar con ella
extern Jugador *estudiante;
Jugador::Jugador(QGraphicsItem *parent)
{

}

void Jugador::keyPressEvent(QKeyEvent *e)
{
    //mover al estudiante de derecha a izquierda

    if(e->key()== Qt::Key_Left){    //Si se presiona la tecla "flecha derecha"
        if(pos().x()>0 ){           //Si en el eje x la posición es mayor a x: si se puede mover
            setPos(x()-10,y());
        }
    }
    else if (e->key() == Qt::Key_Right){
        if(pos().x()+rect().width() < scene()->width()){  //pos+tamaño rectangulo (jugador) < ancho escena: lo mueve
            setPos(x()+10,y());
        }
    }
    else if (e->key() == Qt::Key_Up){
        //if(pos().y()){
            setPos(x(),y()-10);
        //}
    }
    else if (e->key() == Qt::Key_Down){
        if(pos().y()){
            setPos(x(),y()+10);
            }
        }

    QList <QGraphicsItem *> colliding_items = collidingItems(); //Lista de QGraphicsItem.
    //Devuelve una lista de todos los elementos que están colisionando con la droga disparada
    for(int i=0, n=colliding_items.size(); i<n; i++ ){ //Mientras i<n: aumente i
        //Si colisiona con estudiante: la calificación baja
        if(typeid(  *(colliding_items[i])) == typeid(Distractor) ){//typeid retorna tipo de clase/objeto que estamos mirando
            game->nota->disminuir();
            game->estudiante->setPos(10,y()); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente

            return ;
        }
    }

}
