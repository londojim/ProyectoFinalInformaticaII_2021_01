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
    int bxPos = 150;//this->width()/2 -playButton->boundingRect().width()/2
    int byPos = 270;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(click()),this,SLOT(enviarRta()));
    ui->addItem(playButton);

    Acierto= new QMediaPlayer();
}

VReto::~VReto()
{
    delete ui;
}

void VReto::enviarRta()
{
    if (RButton.at(rta)->isChecked()) {
        if(game->numNivel==1){game->nota->aumentar();}
        game->nota->aumentar();
        qDebug()<<"MARCÓ LA RESPUESTA CORRECTA";
        Acierto->setMedia(QUrl("qrc:/s/pass.mp3"));
        Acierto->play();
    }
    else{
        Acierto->setMedia(QUrl("qrc:/s/fail.mp3"));
        Acierto->play();
        qDebug()<<"Envia rta xxx  ";}

        //textos.clear();
        //RButton.clear();
        //delete ui;
        //playButton->disconnect();
        //ui->clear();
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

        for(int i=0; i<4; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("Sinónimos");
        RButton.at(1)->setText("Polisémicas");
        RButton.at(2)->setText("Semánticas");
        RButton.at(3)->setText("Homónimas");
        for(int i=0; i<4; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }

        rta=1;
    }
}
void VReto::retoMat(){

    textos.push_back(new QGraphicsTextItem);
    textos.at(0)->setPlainText(QString("Reto de Matemáticas: "));   //+QString::number(game->nota->getPuntaje()));
    textos.at(0)->setDefaultTextColor(Qt::black);
    textos.at(0)->setFont(QFont("Trajan Pro",15));
    textos.at(0)->setPos(20,15);
    ui->addItem(textos.at(0));

    if(game->numNivel==2){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("¿Qué pesa más, \n un kilo de hierro o un kilo de paja? : "));   //+QString::number(game->nota->getPuntaje()));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",15));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));
        for(int i=0; i<3; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("La paja");
        RButton.at(1)->setText("El hierro");
        RButton.at(2)->setText("Pesan lo mismo");

        for(int i=0; i<3; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }
        rta=2;
    }    else if(game->numNivel==3){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("Son las doce de la mañana, hora de mis pastillas. \nMe tengo que tomar 4 pastillas, una cada 2 horas.\n ¿A qué hora me tomaré la última?"));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",15));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));

        for(int i=0; i<4; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("6:00 am");
        RButton.at(1)->setText("3:00 pm");
        RButton.at(2)->setText("3:00 pm");
        RButton.at(3)->setText("6:00 pm");
        for(int i=0; i<4; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }
        rta=3;
    }
}
void VReto::retoE(){

    textos.push_back(new QGraphicsTextItem);
    textos.at(0)->setPlainText(QString("English challenge: "));   //+QString::number(game->nota->getPuntaje()));
    textos.at(0)->setDefaultTextColor(Qt::black);
    textos.at(0)->setFont(QFont("Trajan Pro",15));
    textos.at(0)->setPos(20,15);
    ui->addItem(textos.at(0));

    if(game->numNivel==1){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("Select the option that correctly answers the question. \nSuppose you like apples\n Do you like apples? : "));   //+QString::number(game->nota->getPuntaje()));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",12));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));
        for(int i=0; i<4; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("Yes, I did");
        RButton.at(1)->setText("Yes, i do");
        RButton.at(2)->setText("Yes, do");
        RButton.at(3)->setText("Yes, I do");
        for(int i=0; i<4; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }
        rta=3;
    }
    else if(game->numNivel==2){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("Select the option that correctly completes the sentence \n How ____ money does she owe you? : "));   //+QString::number(game->nota->getPuntaje()));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",12));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));
        for(int i=0; i<4; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("far");
        RButton.at(1)->setText("many");
        RButton.at(2)->setText("long");
        RButton.at(3)->setText("much");
        for(int i=0; i<4; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }
        rta=3;
    }    else if(game->numNivel==3){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("Select the option that correctly answers the question \n Did she watch the film yesterday? "));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",12));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));

        for(int i=0; i<4; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("Yes, I do");
        RButton.at(1)->setText("no");
        RButton.at(2)->setText("Yes, she did");
        RButton.at(3)->setText("not");
        for(int i=0; i<4; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }

        rta=2;
    }

}
void VReto::retoInfo(){

    textos.push_back(new QGraphicsTextItem);
    textos.at(0)->setPlainText(QString("Reto de informática: "));   //+QString::number(game->nota->getPuntaje()));
    textos.at(0)->setDefaultTextColor(Qt::black);
    textos.at(0)->setFont(QFont("Trajan Pro",15));
    textos.at(0)->setPos(20,15);
    ui->addItem(textos.at(0));

    if(game->numNivel==2){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("Estos son lenguajes de programación interpretados: "));   //+QString::number(game->nota->getPuntaje()));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",15));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));
        for(int i=0; i<4; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("Python, MatLAB, PHP");
        RButton.at(1)->setText("Python, C++, VBA");
        RButton.at(2)->setText("Javascript, Fortran, C");
        RButton.at(3)->setText("C, C++, Ruby");
        for(int i=0; i<4; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }
        rta=0;
    }    else if(game->numNivel==3){
        textos.push_back(new QGraphicsTextItem);
        textos.at(1)->setPlainText(QString("En este tipo de contenedor secuencial los datos \n se almacenan contiguos en memoria"));
        textos.at(1)->setDefaultTextColor(Qt::black);
        textos.at(1)->setFont(QFont("Trajan Pro",15));
        textos.at(1)->setPos(40,80);
        ui->addItem(textos.at(1));

        for(int i=0; i<2; i++){
            RButton.push_back(new QRadioButton);
        }
        RButton.at(0)->setText("Vector");
        RButton.at(1)->setText("Lista");

        for(int i=0; i<2; i++){
            y+=20;
            RButton.at(i)->setGeometry(x,y,100,20);
            ui->addWidget(RButton.at(i));
        }
        rta=0;
    }


}

void VReto::setNum()
{
    this->notaA = game->nota->getPuntaje();
    ui->addText("Nivel " + QString::number(game->numNivel))->setPos(475,10);
    //game->nota->aumentar();
    game->numIntentos++;

}
