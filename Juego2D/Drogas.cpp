#include<Drogas.h>
#include<QGraphicsScene>
#include<QTimer>
#include<QtDebug>

Drogas::Drogas()
{
    //Dibujar la droga que será disparada por un objeto tipo distractor
    setRect(0,0,10,50); //Damos posicion el origen y un tamaño
    //Creamos la señal para poder conectar el timer
    QTimer *timerDroga = new QTimer(this);
    connect(timerDroga, SIGNAL(timeout()),this,SLOT(movimientoDroga));  //La funcion que conectamos se va a ejecutar en cada flaco de reloj del sistema
    timerDroga->start(80);  //En milisegundos
}

void Drogas::movimientoDroga()
{
    setPos(x()-10,y());             //Por la ubicación del amigo, la droga irá a la  izquierda
    if(pos().x()+rect().width()<0)  //Eliminar la droga cuando sale de la escena
        {
        scene()->removeItem(this);
        qDebug()<<"Salió de la escena y se borró exitosamente";
    }
}
