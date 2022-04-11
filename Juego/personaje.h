#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <string>
#include <QPainter>
#include <QPixmap>

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

using namespace std;

class Personaje: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT


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

public:
    //Para solucionar el error de que personaje sea clase abstracta, les defino comportamiento a estas dos funciones virtuales, que son heredadas de QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);



    //Métodos

};

#endif // PERSONAJE_H
