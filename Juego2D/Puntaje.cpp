#include<QFont>
#include<Puntaje.h>
#include <chrono>
#include <thread>

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
    //std::this_thread::sleep_for (std::chrono::seconds(1));

}

int Puntaje::getPuntaje()
{
    return nota;
}

