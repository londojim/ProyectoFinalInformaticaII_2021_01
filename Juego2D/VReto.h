#ifndef VRETO_H
#define VRETO_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include <Game.h>
#include<QMainWindow>
#include<string>
#include<QRadioButton>
#include<QButtonGroup >
#include<QVBoxLayout>


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
    QList<QGraphicsTextItem *> textos;
    QList<QRadioButton *> RButton;
    QButtonGroup  * Box = new QButtonGroup ;
    int x=200;
    int y=150;
   int notaA;
};


#endif // VRETO_H
