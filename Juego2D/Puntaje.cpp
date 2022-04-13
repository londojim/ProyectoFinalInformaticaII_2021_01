#include<QFont>
#include<Puntaje.h>

Puntaje::Puntaje(QGraphicsItem *parent)
{
    nota = 11;
    // dibujar el texto
    setPlainText(QString("Calificación: ")+QString::number(nota));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Puntaje::disminuir()
{
    nota-=10;
    setPlainText(QString("Score: ")+QString::number(nota));
}

int Puntaje::getPuntaje()
{
    return nota;
}

