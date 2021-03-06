#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include<Jugador.h>
#include<Distractor.h>
#include<Asignaturas.h>
#include<AmigoD.h>
#include<Puntaje.h>
#include<vreto.h>
#include<QMediaplayer>
#include<profesor.h>
#include <QMainWindow>

#include <QMainWindow>


// Clase que contendrá la escena donde pondremos los objetos que van a interactuar
class Game: public QGraphicsView{ //Hereda así para poder crear el view donde pondremos todo en escena
    Q_OBJECT
public:
    Game(QWidget *parent = 0); //Constructor así para evitar errores por tener un constructor vacío
    void menu();
    void GameOver();
    void nivel1();
    void nivel2();
    void nivel3();
    void felicidades();
    void Cronometro();

   QGraphicsScene *scene;   //Para la escena que tendremos
    Jugador * estudiante;
    AmigoD  * amigo;
    AmigoD  * amigo1;
    Distractor  * consola;
    Distractor  * consola2;
    Asignaturas * informatica;
    Asignaturas * english;
    Asignaturas * lecto;
    Asignaturas * mat;
    Puntaje * nota;
    Profesor *Augusto;

    int llamado=0;

    //Pruebas para las ventanas emergentes
    int numIntentos;
    int numNivel;
    //Para la  musica
    QMediaPlayer *musica;
    QMediaPlayer *m;

public slots:
    void start();
    void exit();
    int Nivel();
    int Reto();

};
#endif // GAME_H
