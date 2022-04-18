#include "vreto.h"
#include<QFont>
#include<mainwindow.h>
#include<string>

extern Game *game;

VReto::VReto(QWidget *parent)
{
    ui = new QGraphicsScene();
    ui->setSceneRect(0,0,508,340);   //En el origen; redefinimos alto y ancho
    ui->clear();

    setBackgroundBrush(QBrush(QImage(":/imagenes/reto.jpg")));
    setScene(ui);    //Para poder visualizar la escena
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

VReto::~VReto()
{
    delete ui;
}

void VReto::retoLecto(){
    QGraphicsTextItem *As = new QGraphicsTextItem;
    As->setPlainText(QString("Reto de lectoescritura: "));   //+QString::number(game->nota->getPuntaje()));
    As->setDefaultTextColor(Qt::black);
    As->setFont(QFont("Trajan Pro",15));
    As->setPos(20,15);
    ui->addItem(As);
}
void VReto::retoMat(){
    QGraphicsTextItem *As = new QGraphicsTextItem;
    As->setPlainText(QString("Reto de Matemáticas: "));   //+QString::number(game->nota->getPuntaje()));
    As->setDefaultTextColor(Qt::black);
    As->setFont(QFont("Trajan Pro",15));
    As->setPos(20,15);
    ui->addItem(As);

}
void VReto::retoE(){
    QGraphicsTextItem *As = new QGraphicsTextItem;
    As->setPlainText(QString("English challenge: "));   //+QString::number(game->nota->getPuntaje()));
    As->setDefaultTextColor(Qt::black);
    As->setFont(QFont("Trajan Pro",15));
    As->setPos(20,15);
    ui->addItem(As);

}
void VReto::retoInfo(){
    QGraphicsTextItem *As = new QGraphicsTextItem;
    As->setPlainText(QString("Reto de informática: "));   //+QString::number(game->nota->getPuntaje()));
    As->setDefaultTextColor(Qt::black);
    As->setFont(QFont("Trajan Pro",15));
    As->setPos(20,15);
    ui->addItem(As);
}

void VReto::setNum()
{
    this->notaA = game->nota->getPuntaje();
    ui->addText("Nivel " + QString::number(game->numNivel))->setPos(475,10);
    game->nota->aumentar();
    game->numIntentos++;


}
