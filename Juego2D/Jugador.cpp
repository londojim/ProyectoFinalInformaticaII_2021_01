#include<Jugador.h>
#include<QGraphicsScene>
#include<QKeyEvent>         //Para que reconozca pulsaciones del teclado
#include<Game.h>
extern Game *game;  //Llamamos una vble externa para interactuar con ella
extern Jugador *estudiante;
/*
extern Asignaturas *mat;
extern Asignaturas *lecto;
extern Asignaturas *english;
extern Asignaturas *informatica;
*/

Jugador::Jugador(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
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
        if(pos().x()+pixmap().width() < scene()->width()){  //pos+tamaño rectangulo (jugador) < ancho escena: lo mueve
            setPos(x()+10,y());
        }
    }
    else if (e->key() == Qt::Key_Up){
        if(pos().y()+pixmap().height()>115){
            setPos(x(),y()-10);
        }
    }
    else if (e->key() == Qt::Key_Down){
        if(pos().y()+pixmap().height()+10 <scene()->height()){
            setPos(x(),y()+10);
            }
        }

    QList <QGraphicsItem *> colliding_items = collidingItems(); //Lista de QGraphicsItem.
    //Devuelve una lista de todos los elementos que están colisionando con la droga disparada
    for(int i=0, n=colliding_items.size(); i<n; i++ ){ //Mientras i<n: aumente i
        //Si colisiona con estudiante: la calificación baja
        if(typeid(  *(colliding_items[i])) == typeid(Distractor) ){//typeid retorna tipo de clase/objeto que estamos mirando
            STocaPacman= new QMediaPlayer();
            STocaPacman->setMedia(QUrl("qrc:/s/TocaPacman.mp3"));
            STocaPacman->play();
            game->nota->disminuir();
            game->estudiante->setPos(10,y()); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente

            return ;
        }
        if(typeid(  *(colliding_items[i])) == typeid(Profesor) ){//typeid retorna tipo de clase/objeto que estamos mirando
            SAsesoria= new QMediaPlayer();
            SAsesoria->setMedia(QUrl("qrc:/s/pass.mp3"));
            SAsesoria->play();
            game->nota->aumentar();
            game->estudiante->setPos(10,500); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente

            return ;
        }

    }

}
