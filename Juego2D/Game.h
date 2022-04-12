#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include<Jugador.h>
#include<Distractor.h>
#include<Asignaturas.h>
#include<AmigoD.h>

// Clase que contendrá la escena donde pondremos los objetos que van a interactuar
class Game: public QGraphicsView{ //Hereda así para poder crear el view donde pondremos todo en escena
    //Q_OBJECT
public:
    Game(QWidget *parent = 0); //Constructor así para evitar errores por tener un constructor vacío

    //void menu();

    QGraphicsScene *scene;   //Para la escena que tendremos
    //QGraphicsScene *scene1;

    Jugador * estudiante;
    AmigoD  * amigo;
    Distractor  * consola;
    Distractor  * cama;
    Asignaturas * informatica;
    Asignaturas * english;
    Asignaturas * lecto;
    Asignaturas * mat;

    /*
    Score * score;
    Health * health;
    QMediaPlayer * music;
public slots:
    void start();*/


};
#endif // GAME_H
