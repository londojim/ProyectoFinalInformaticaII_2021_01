#include "vreto.h"


VReto::VReto(QWidget *parent)
{
    ui = new QGraphicsScene();
    ui->setSceneRect(0,0,800,600);   //En el origen; redefinimos alto y ancho
    //music = new QMediaPlayer();
    setScene(ui);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(600,600);
    ui->addText("Bienvenido a un nuevo reto")->setFont(QFont("Trajan Pro",20));
    contador=0;
}

VReto::~VReto()
{
    delete ui;
}

void VReto::setNum(int newNum)
{
    num = newNum;
    contador++;

}
