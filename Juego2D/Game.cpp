#include<Game.h>
#include<Jugador.h>
#include<Distractor.h>
#include<Asignaturas.h>
#include<AmigoD.h>
#include<QTimer>
#include<QMediaPlayer>
#include<QBrush>
#include<QImage>
#include<QFont>

Game::Game(QWidget *parent)
{
    //Musica de fondo
    musica = new QMediaPlayer();
    musica->setMedia(QUrl("qrc:/s/Fondo.mp3"));
    musica->play();
    //***********CREACIÓN ESCENA NIVEL 2****************
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);   //En el origen; redefinimos alto y ancho
    setBackgroundBrush(QBrush(QImage(":/imagenes/biblioteca.png")));
    setScene(scene);    //Para poder visualizar la escena
    //***********FIJAR LA ESCENA HORIZONTAL Y VERTICALMENTE****************
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    scene->addText("Nivel 2")->setPos(400,0);//->setFont(QFont("Trajan Pro",20));
    nota = new Puntaje();
    scene->addItem(nota);
    //***********CREACIÓN JUGADOR*********************
    estudiante = new Jugador();
    estudiante->setPos(150,500);
    estudiante->setPixmap(QPixmap(":/imagenes/estudianteM.png"));

    //Movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene->addItem(estudiante);
    //***********CREACIÓN DISTRACTORES****************
    amigo = new AmigoD();
    amigo->setPos(675,500);
    scene->addItem(amigo);
    //***************************
    cama = new Distractor();
    cama->setPos(350,300);
    scene->addItem(cama);
    //***********CREACIÓN ASIGNATURAS***************
    mat = new Asignaturas();
    mat->setPos(85,180);
    scene->addItem(mat);
    //***************************
    english = new Asignaturas();
    english->setPos(350,100);
    scene->addItem(english);
    //***************************
    informatica = new Asignaturas();
    informatica->setPos(600,50);
    scene->addItem(informatica);
    //***********DISPAROS DE AMIGO****************
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
    timer->start(3000);
    //***************************
show();
/*
    if(&nota){
        VReto *vIngles = new VReto;
        vIngles->show();

    }
    */


/*
    //***********CREACIÓN ESCENA NIVEL 1****************
    scene1 = new QGraphicsScene();
    scene1->setSceneRect(0,0,800,600);   //En el origen; redefinimos alto y ancho
    //music = new QMediaPlayer();
    setScene(scene1);    //Para poder visualizar la escena
    nota = new Puntaje();
    scene1->addItem(nota);
    //***********FIJAR LA ESCENA HORIZONTAL Y VERTICALMENTE****************
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    scene1->addText("Nivel 1")->setPos(400,0);//->setFont(QFont("Trajan Pro",20));
    //***********CREACIÓN JUGADOR*********************
    estudiante = new Jugador();         //Como heredó todo de RectItem podemos usar esos métodos
    estudiante->setRect(0,500,50,80);   //Ubicado en el origen. Tamaño 50X80
    //Movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene1->addItem(estudiante);
    //***********CREACIÓN DISTRACTORES****************
    amigo = new AmigoD();
    amigo->setPos(675,500);
    scene1->addItem(amigo);
    //***************************
    consola = new Distractor();
    consola->setPos(360,175);
    scene1->addItem(consola);
    //***********CREACIÓN ASIGNATURAS***************
    lecto = new Asignaturas();
    lecto->setPos(200,300);
    scene1->addItem(lecto);
    //***************************
    english = new Asignaturas();
    english->setPos(550,220);
    scene1->addItem(english);
    //***********DISPAROS DE AMIGO****************
    //QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
    timer->start(5000);
    //***************************

    show();
*/
}

