#include<Game.h>
#include<Jugador.h>
#include<Distractor.h>
#include<Asignaturas.h>
#include<AmigoD.h>
#include<QTimer>


Game::Game(QWidget *parent)
{

    /***********CREACIÓN ESCENA NIVEL 2****************/
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);   //En el origen; redefinimos alto y ancho
    //music = new QMediaPlayer();
    setScene(scene);    //Para poder visualizar la escena
    /***********FIJAR LA ESCENA HORIZONTAL Y VERTICALMENTE****************/
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    /***********CREACIÓN JUGADOR*********************/
    estudiante = new Jugador();         //Como heredó todo de RectItem podemos usar esos métodos
    estudiante->setRect(0,500,50,80);   //Ubicado en el origen. Tamaño 50X80
    //Movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene->addItem(estudiante);
    /***********CREACIÓN DISTRACTORES****************/
    amigo = new AmigoD();
    amigo->setPos(675,500);
    scene->addItem(amigo);
    /***************************/
    consola = new Distractor();
    consola->setPos(350,300);
    scene->addItem(consola);
    scene->addText("Xbox")->setPos(370,280);
    /***********CREACIÓN ASIGNATURAS***************/
    mat = new Asignaturas();
    mat->setPos(85,180);
    scene->addItem(mat);
    scene->addText("Matemáticas")->setPos(85,150);
    /***************************/
    english = new Asignaturas();
    english->setPos(350,100);
    scene->addItem(english);
    scene->addText("Inglés")->setPos(360,75);
    /***************************/
    informatica = new Asignaturas();
    informatica->setPos(600,50);
    scene->addItem(informatica);
    scene->addText("Informática")->setPos(600,25);
    /***********DISPAROS DE AMIGO****************/
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
    timer->start(3000);
    /***************************/


    show();
}
