#include "personaje.h"
#include "estudiante.h"


Estudiante::Estudiante(string nombre,
           int posx,
           int posy,
           int velocidad){

    Personaje::nombre=nombre;
    Personaje::posx=posx;
    Personaje::posy=posy;
    this->velocidad =velocidad;
    setPos(posx,posy);

}

Estudiante::~Estudiante()
{

}



void Estudiante::MoverArriba()
{
    setPos(posx,posy-velocidad);
}

void Estudiante::MoverAbajo()
{
    setPos(posx,posy+velocidad);
}

void Estudiante::MoverDerecha()
{
    setPos(posx+velocidad,posy);
}

void Estudiante::MoverIzquierda()
{
    setPos(posx+velocidad,posy);
}
