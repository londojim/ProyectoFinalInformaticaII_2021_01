#include<Game.h>
#include<Jugador.h>
#include<Distractor.h>

Game::Game(QWidget *parent)
{
    //crear la scena
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);   //En el origen; redefinimos alto y ancho

    //music = new QMediaPlayer();

    setScene(scene);    //Para poder visualizar la escena

    //Para que la escena no se mueva entonces el view lo dejamos quieto, tanto horizontal como vertical
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Creamos el jugador
    estudiante = new Jugador();         //Como heredó todo de RectItem podemos usar esos métodos
    estudiante->setRect(0,0,100,100);   //Ubicado en el origen. Tamaño 100x100
    estudiante->setPos(400,500);        //Cambiamos de posición
    //Para el movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene->addItem(estudiante);


    //Creamos un distractor

    amigo = new Distractor();         //Como heredó todo de RectItem podemos usar esos métodos
    amigo->setRect(0,0,100,100);
    amigo->setPos(400,500);         //Cambiamos de posición
    scene->addItem(amigo);


    show();
}
