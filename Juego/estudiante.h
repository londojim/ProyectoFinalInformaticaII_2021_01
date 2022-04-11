#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <personaje.h>
#include <string>


using namespace std;

class Estudiante: public Personaje
{

    //Atributos
    int velocidad;
    int puntaje=0;

public:

    Estudiante(string nombre,
               int posx,
               int posy,
               int velocidad);

    ~Estudiante();

};

#endif // ESTUDIANTE_H
