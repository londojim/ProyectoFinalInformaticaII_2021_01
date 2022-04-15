#ifndef VRETO_H
#define VRETO_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include <Game.h>
#include<QMainWindow>

namespace Ui {
class VReto;
}

class VReto: public QGraphicsView
{
    Q_OBJECT

public:
    explicit VReto(QWidget *parent = nullptr);
    ~VReto();

    void setNum(int newNum);

private:
    QGraphicsScene *ui;
    VReto *vMatematicas= new VReto; //Ventana emergente para la asignatura Matemáticas
    VReto *vInformatica= new VReto;
    VReto *vIngles= new VReto;

    int num;
    int contador;
};


#endif // VRETO_H
