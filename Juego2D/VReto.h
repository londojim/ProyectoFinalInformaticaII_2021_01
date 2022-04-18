#ifndef VRETO_H
#define VRETO_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include <Game.h>
#include<QMainWindow>
#include<string>

namespace Ui {
class VReto;
}

class VReto: public QGraphicsView
{
    Q_OBJECT

public:
    explicit VReto(QWidget *parent = nullptr);
    ~VReto();
    QGraphicsScene *ui;
     //Indica que asignatura es

    void setNum();

    void retoLecto();
    void retoMat();
    void retoE();
    void retoInfo();

   int notaA;
};


#endif // VRETO_H
