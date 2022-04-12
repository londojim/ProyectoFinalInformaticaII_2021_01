#include<Game.h>
#include<Jugador.h>
#include<Distractor.h>
#include<Asignaturas.h>
#include<AmigoD.h>
#include<QTimer>


Game::Game(QWidget *parent)
{
    /***********CREACIÓN ESCENA****************/
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);   //En el origen; redefinimos alto y ancho
    //music = new QMediaPlayer();
    setScene(scene);    //Para poder visualizar la escena
    //Para que la escena no se mueva entonces el view lo dejamos quieto, tanto horizontal como vertical
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    /***********CREACIÓN JUGADOR*********************/
    estudiante = new Jugador();         //Como heredó todo de RectItem podemos usar esos métodos
    estudiante->setRect(0,500,80,80);   //Ubicado en el origen. Tamaño 100x100
    //Movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene->addItem(estudiante);
    /***********CREACIÓN DISTRACTORES****************/
    amigo = new AmigoD();           //Como heredó todo de RectItem podemos usar esos métodos
    amigo->setPos(675,500);             //Cambiamos de posición
    scene->addItem(amigo);
    /***************************/
    consola = new Distractor();
    consola->setPos(100,200);           //Dibujamos la consola
    scene->addItem(consola);
    /***************************/
    cama = new Distractor();
    cama->setPos(400,150);
    scene->addItem(cama);
    //Movimiento de los distractores

    /******************************/
    mat = new Asignaturas();
    mat->setPos(450,300);
    scene->addItem(mat);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
    timer->start(1000);


    show();
}
