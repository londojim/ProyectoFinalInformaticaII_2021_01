#include<Jugador.h>
#include<QGraphicsScene>
#include<QKeyEvent>         //Para que reconozca pulsaciones del teclado


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
}
