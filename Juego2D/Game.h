#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>

// Clase que contendrá la escena donde pondremos los objetos que van a interactuar
class Game: public QGraphicsView{ //Hereda así para poder crear el view donde pondremos todo en escena
    //Q_OBJECT
public:
    Game(QWidget *parent = 0); //Constructor así para evitar errores por tener un constructor vacío

    //void menu();

    QGraphicsScene *scene;   //Para la escena que tendremos
    /*
    Player * player;
    Score * score;
    Health * health;
    QMediaPlayer * music;
public slots:
    void start();*/


};
#endif // GAME_H