#include<Drogas.h>
#include<QGraphicsScene>
#include<QTimer>

Drogas::Drogas()
{
    //Dibujar la droga que será disparada por un objeto tipo distractor
    setRect(0,0,10,50); //Damos posicion el origen y un tamaño
    //Creamos la señal para poder conectar el timer
    QTimer *timerDroga = new QTimer();
    connect(timerDroga, SIGNAL(timeout()),this,SLOT(movimientoDroga));  //La funcion que conectamos se va a ejecutar en cada flaco de reloj del sistema
    timerDroga->start(80);  //En milisegundos
}

void Drogas::movimientoDroga()
{
    setPos(x()-10,y()); //Por la ubicación del amigo, la bala irá a la  izquierda
}
