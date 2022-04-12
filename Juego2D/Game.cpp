#include<Game.h>


Game::Game(QWidget *parent)
{
    //crear la scena
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);   //En el origen; redefinimos alto y ancho

    //music = new QMediaPlayer();

    setScene(scene);    //Para poder visualizar la escena
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

}
