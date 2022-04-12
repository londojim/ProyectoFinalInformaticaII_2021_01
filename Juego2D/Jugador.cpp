#include<Jugador.h>
#include<QGraphicsScene>
#include<QKeyEvent>         //Para que reconozca pulsaciones del teclado

Jugador::Jugador(QGraphicsItem *parent)
{

}

void Jugador::KeyPressEvent(QKeyEvent *e)
{
    //mover al estudiante de derecha a izquierda

    if(e->key()== Qt::Key_Left){    //Si se presiona la tecla "flecha derecha"
        setPos(x()-10,y());
    }
    else if (e->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
}
