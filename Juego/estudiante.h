#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <personaje.h>
#include <string>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPixmap>


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

    //Métodos
    void MoverArriba();      //Método para mover arriba
    void MoverAbajo();    //Método para mover abajo
    void MoverDerecha();   //Método para mover a la derecha
    void MoverIzquierda();    //Método para mover a la izquierda
    setPixmap();


};

#endif // ESTUDIANTE_H
