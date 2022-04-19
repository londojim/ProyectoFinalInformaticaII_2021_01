#ifndef ASIGNATURAS_H
#define ASIGNATURAS_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include <QObject>

class Asignaturas: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Asignaturas(QGraphicsItem *parent = 0);
public slots:
    void movAsignatura();     //Señal conectada al timer para tener un movimiento periodico
private:
    //bool BArriba;
    float vx; float vy=0;   //Velocidades en los ejes x,y;
    float ax, ay;           //Aceleraciones en los ejes x,y;
    float g=0.1; float t = 0.28;
    int masa=1;
    int k=4;            //Constante del resorte
    int fuerzaResorte;  //FuerzaResorte = -k*desplazamiento; desplazamiento es distancia del anclaje a la masa
    int fuerzasY;
    float anclajeY;     //Posición del anclaje del resorte en el eje y
                        //Establecer el valor del anclaje de mood que esté encimita de la posición del objeto

};

#endif // ASIGNATURAS_H
