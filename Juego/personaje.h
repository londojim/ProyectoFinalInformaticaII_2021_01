#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <string>
#include <QPainter>


using namespace std;

class Personaje: public QGraphicsItem
{


    //Atributos
    protected:
    int posy;
    int posx;
    string nombre;

protected:
    //Constructores
    Personaje();
    Personaje(string nombre, int posx,int posy);
    ~Personaje();

    //Para solucionar el error de que personaje sea clase abstracta, les defino comportamiento a estas dos funciones virtuales, que son heredadas de QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);


    //Métodos
    /*
    void MoveUp();      //Método para mover arriba
    void MoveDown();    //Método para mover abajo
    void MoveRigth();   //Método para mover a la derecha
    void MoveLeft();    //Método para mover a la izquierda
    */















};

#endif // PERSONAJE_H
