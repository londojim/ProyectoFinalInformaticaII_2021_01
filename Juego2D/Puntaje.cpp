#include<QFont>
#include<Puntaje.h>
//#include <chrono> //Para la pausa en el juego al detectar la colision
//#include <thread>

Puntaje::Puntaje(QGraphicsItem *parent)
{
    nota = 11;
    // dibujar el texto
    setPlainText(QString("Calificación: ")+QString::number(nota));
    setDefaultTextColor(Qt::blue);

    setFont(QFont("times",16));
}
void Puntaje::aumentar()
{
    nota+=10;
    setPlainText(QString("Score: ")+QString::number(nota));
}

void Puntaje::disminuir()
{
    nota-=10;
    setPlainText(QString("Score: ")+QString::number(nota));
    //std::this_thread::sleep_for (std::chrono::seconds(1)); //Para evitar que el puntaje se reste
                                                               //varias veces mientras el jugador se aparta

}

int Puntaje::getPuntaje()
{
    return nota;
}

