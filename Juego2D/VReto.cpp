#include "vreto.h"
#include<QFont>
#include<mainwindow.h>
#include<string>
#include <QRadioButton>
#include<QTimer>
#include<Boton.h>
#include<QDebug>

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

    // crear boton enviar respuesta
    Boton * playButton = new Boton(QString("Enviar"));
    int bxPos = 150;//this->width()/2 -playButton->boundingRect().width()/2
    int byPos = 270;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(click()),this,SLOT(enviarRta()));
    ui->addItem(playButton);
}

VReto::~VReto()
{
    delete ui;
}

void VReto::enviarRta()
{   //textos.clear();
    //RButton.clear();
    //delete ui;
    if (RButton.at(rta)->isChecked()) {
        game->nota->aumentar();
        qDebug()<<"MARCÓ LA RESPUESTA CORRECTA";
    }
    else{
    qDebug()<<"Envia rta xxx  ";}
    this->close();
}
void VReto::retoLecto(){
    textos.push_back(new QGraphicsTextItem);
    textos.at(0)->setPlainText(QString("Reto de lectoescritura: "));   //+QString::number(game->nota->getPuntaje()));
    textos.at(0)->setDefaultTextColor(Qt::black);
    textos.at(0)->setFont(QFont("Trajan Pro",15));
    textos.at(0)->setPos(20,15);
    ui->addItem(textos.at(0));

    if(game->numNivel==1){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("¿Cómo se denominan las palabras que tienen \n igual significado, pero diferente escritura? "));   //+QString::number(game->nota->getPuntaje()));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",15));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));
        for(int i=0; i<4; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("Polisémicas");
        RButton.at(1)->setText("Trambólicas");
        RButton.at(2)->setText("Homónimas");
        RButton.at(3)->setText("Sinónimos");
        for(int i=0; i<4; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }

        rta=3;
    }    else if(game->numNivel==3){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("¿Cómo se denominan las palabras que tienen \n igual escritura, pero diferente significado? "));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",15));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));
    }
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
    //game->nota->aumentar();
    game->numIntentos++;

}
