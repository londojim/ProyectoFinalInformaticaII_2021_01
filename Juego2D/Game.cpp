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
#include<Boton.h>
#include<profesor.h>
#include<Drogas.h>
#include<Puntaje.h>
#include<QDebug>
#include<vreto.h>

//extern VReto *reto;

QTimer *timerNivel = new QTimer();
QTimer *timerReto = new QTimer();
QTimer *timer = new QTimer();   //disparo amigoD
QTimer *timer1 = new QTimer();  //Dispato otroamiigoD

QList<Distractor *> Distractores;
QList<Asignaturas *> ListaAsignatura;

//Creamos un objeto tipo VReto, que es el que contendrá la escena del reto
VReto *reto;

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    musica = new QMediaPlayer();
    m = new QMediaPlayer();

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //numNivel=1;     //Añadir validación nota...
}


void Game::menu()
{
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":imagenes/fuente.jpg")));

    musica->setMedia(QUrl("qrc:/s/menu.mp3"));
    musica->play();
    numNivel=1;

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Salvando el semestre"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);

    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // crear boton play
    Boton * playButton = new Boton(QString("Jugar"));
    int bxPos = 65;//this->width()/2 -playButton->boundingRect().width()/2
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(click()),this,SLOT(start()));
    scene->addItem(playButton);

    // crear boton salir
    Boton * quitButton = new Boton(QString("Salir"));
    int qxPos = 65;//this->width()/2 -quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(playButton,SIGNAL(click()),this,SLOT(exit()));
    scene->addItem(quitButton);

}

void Game::start()
{
    //Musica de fondo
    musica->setMedia(QUrl("qrc:/s/Fondo.mp3"));
    musica->play();
    Distractores.clear();
    ListaAsignatura.clear();

    nota = new Puntaje();
    if(numNivel==1){
        nivel1();
    }else if(numNivel==2){
        nivel2();
    }
    else if(numNivel==3){
        nivel3();

    }

}

void Game::exit()
{
    scene->clear();
this->close();
}
int Game::Nivel()
{

    qDebug()<<"EL PUNTAJE VA EN";
    qDebug()<<nota->getPuntaje();
    switch (numNivel){
    case 1:
        if(nota->getPuntaje()>=60){
            //timerNivel->disconnect();
            //timerReto->disconnect();
            numNivel=2;
            start();

        }
        else if(nota->getPuntaje()<0){
            timerNivel->disconnect();
            timerReto->disconnect();
            GameOver();
        }
        break;

    case 2:
        if(nota->getPuntaje()>=60){
            timerNivel->disconnect();
            numNivel=3;
            start();
        }
        else if(nota->getPuntaje()<0){
            timerNivel->disconnect();
            timerReto->disconnect();
            GameOver();
            break;
        }

        break;
    case 3:
        if(nota->getPuntaje()>=60){
            timerNivel->disconnect();
            timerReto->disconnect();
            felicidades();
        }
        else if(nota->getPuntaje()<0){
            timerNivel->disconnect();
            timerReto->disconnect();
            GameOver();
            break;
        }
        break;
    }
    return llamado;
}

void Game::GameOver()
{
    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/imagenes/GameOver.png")));
    musica->setMedia(QUrl("qrc:/s/menu.mp3"));
    musica->play();
    numNivel=1;

    // crear boton re-intento
    Boton * playButton = new Boton(QString("Jugar"));
    int bxPos = 65;//this->width()/2 -playButton->boundingRect().width()/2
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(click()),this,SLOT(start()));
    scene->addItem(playButton);

    // crear boton salir
    Boton * quitButton = new Boton(QString("Salir"));
    int qxPos = 65;//this->width()/2 -quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(playButton,SIGNAL(click()),this,SLOT(exit()));
    scene->addItem(quitButton);

}

void Game::nivel1(){
    //PINTANDO LA ESCENA NIVEL 1
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/imagenes/bloqueING.png")));
    setScene(scene);    //Para poder visualizar la escena
    scene->addItem(nota);
    scene->addText("Nivel 1")->setPos(400,0);//->setFont(QFont("Trajan Pro",20));

    //CREACIÓN JUGADOR
    estudiante = new Jugador();
    estudiante->setPos(120,520);
    estudiante->setPixmap(QPixmap(":/imagenes/estudianteH.png"));
    //Movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene ->addItem(estudiante);

    //*CREACIÓN DISTRACTORES
    consola = new Distractor();
    Distractores.push_back(consola);
    Distractores.at(0)->setPos(350,175);
    scene->addItem(Distractores.at(0));

    consola2 = new Distractor();
    Distractores.push_back(consola2);
    Distractores.at(1)->setPos(450,400);
    scene->addItem(Distractores.at(1));

    amigo = new AmigoD();
    amigo->setPos(675,280);
    scene->addItem(amigo);
    //DISPAROS DE AMIGO
    QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
    timer->start(5000);

    //CREACIÓN ASIGNATURAS
    lecto = new Asignaturas();
    ListaAsignatura.push_back(lecto);
    ListaAsignatura.at(0)->setPos(200,280);
    scene->addItem(ListaAsignatura.at(0));

    english = new Asignaturas();
    ListaAsignatura.push_back(english);
    ListaAsignatura.at(1)->setPos(550,200);
    scene->addItem(ListaAsignatura.at(1));

    QObject::connect(timerNivel, SIGNAL(timeout()),this, SLOT(Nivel()));
    timerNivel->start(1000);

    QObject::connect(timerReto, SIGNAL(timeout()),this, SLOT(Reto()));
    timerReto->start(800);

    show();
}
void Game::nivel2(){
    //PINTANDO LA ESCENA NIVEL 2/
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/imagenes/biblioteca.png")));
    setScene(scene);    //Para poder visualizar la escena
    scene->addText("Nivel 2")->setPos(400,0);//->setFont(QFont("Trajan Pro",20));
    scene->addItem(nota);

    //CREACIÓN JUGADOR
    estudiante = new Jugador();
    estudiante->setPos(580,450);
    estudiante->setPixmap(QPixmap(":/imagenes/estudianteM.png"));
    //Movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene->addItem(estudiante);

    //CREACIÓN DISTRACTORES
    amigo = new AmigoD();
    amigo->setPos(675,300);
    scene->addItem(amigo);

    QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
    timer->start(3000);

    consola = new Distractor();
    Distractores.push_back(consola);
    Distractores.at(0)->setPos(350,300);
    scene->addItem(Distractores.at(0));

    //***********CREACIÓN ASIGNATURAS***************
    mat = new Asignaturas();
    ListaAsignatura.push_back(mat);
    ListaAsignatura.at(0)->setPos(85,180);
    scene->addItem(ListaAsignatura.at(0));


    english = new Asignaturas();
    ListaAsignatura.push_back(english);
    ListaAsignatura.at(1)->setPos(350,100);
    scene->addItem(ListaAsignatura.at(1));

    informatica = new Asignaturas();
    ListaAsignatura.push_back(informatica);
    ListaAsignatura.at(2)->setPos(600,50);
    scene->addItem(ListaAsignatura.at(2));

    QObject::connect(timerNivel, SIGNAL(timeout()),this, SLOT(Nivel()));
    timerNivel->start(1000);
    QObject::connect(timerReto, SIGNAL(timeout()),this, SLOT(Reto()));
    timerReto->start(800);

    show();
}
void Game::nivel3(){
    //PINTANDO LA ESCENA NIVEL 3/
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/imagenes/barrientos.jpg")));
    setScene(scene);    //Para poder visualizar la escena
    scene->addText("Nivel 2")->setPos(400,0);//->setFont(QFont("Trajan Pro",20));
    scene->addItem(nota);

    //CREACIÓN JUGADOR
    estudiante = new Jugador();
    estudiante->setPos(600,500);
    estudiante->setPixmap(QPixmap(":/imagenes/estudianteM.png"));
    //Movimiento del jugador
    estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
    estudiante->setFocus();
    scene->addItem(estudiante);

    //CREACIÓN PROFESOR
    Augusto = new Profesor();
    Augusto->setPos(30,85);
    Augusto->setPixmap(QPixmap(":/imagenes/profe.png"));
    scene->addItem(Augusto);


    //CREACIÓN DISTRACTORES
    amigo = new AmigoD();
    amigo->setPos(675,400);
    scene->addItem(amigo);

    QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
    timer->start(1850);

    amigo1 = new AmigoD();
    amigo1->setPos(675,200);
    scene->addItem(amigo1);

    QObject::connect(timer1, SIGNAL(timeout()),amigo1, SLOT(Disparar()));
    timer1->start(3000);

    consola = new Distractor();
    Distractores.push_back(consola);
    Distractores.at(0)->setPos(355,230);
    scene->addItem(Distractores.at(0));

    //***********CREACIÓN ASIGNATURAS***************
    mat = new Asignaturas();
    ListaAsignatura.push_back(mat);
    ListaAsignatura.at(0)->setPos(360,480);
    scene->addItem(ListaAsignatura.at(0));

    english = new Asignaturas();
    ListaAsignatura.push_back(english);
    ListaAsignatura.at(1)->setPos(345,100);
    scene->addItem(ListaAsignatura.at(1));

    informatica = new Asignaturas();
    ListaAsignatura.push_back(informatica);
    ListaAsignatura.at(2)->setPos(600,50);
    scene->addItem(ListaAsignatura.at(2));

    lecto = new Asignaturas();
    ListaAsignatura.push_back(lecto);
    ListaAsignatura.at(3)->setPos(150,300);
    scene->addItem(ListaAsignatura.at(3));

    QObject::connect(timerNivel, SIGNAL(timeout()),this, SLOT(Nivel()));
    timerNivel->start(1000);
    QObject::connect(timerReto, SIGNAL(timeout()),this, SLOT(Reto()));
    timerReto->start(800);
    show();

}
void Game::felicidades(){
    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/imagenes/fuente.jpg")));
    musica->setMedia(QUrl("qrc:/s/menu.mp3"));
    musica->play();
    numNivel=1;

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("¡PASASTE EL SEMESTRE!"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // crear boton play
    Boton * playButton = new Boton(QString("Jugar de nuevo"));
    int bxPos = 65;//this->width()/2 -playButton->boundingRect().width()/2
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(click()),this,SLOT(start()));
    scene->addItem(playButton);
}

int Game::Reto(){


    if(numNivel==1){
        if(estudiante->collidesWithItem(lecto)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            //lecto->setPos(810,610);
            reto= new VReto;
            reto->setNum();
            reto->retoLecto();
            reto->show();
        }
        else if(estudiante->collidesWithItem(english)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            reto= new VReto;
            reto->setNum();
            reto->retoE();
            reto->show();

        }
    }

    else if(numNivel==2){
        if(estudiante->collidesWithItem(english)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente

            //delete colliding_items[i];
            //delete this;
            reto= new VReto;
            reto->setNum();
            reto->retoE();
            reto->show();

        }
        else if(estudiante->collidesWithItem(mat)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            reto= new VReto;
            reto->setNum();
            reto->retoMat();
            reto->show();

        }
        else if(estudiante->collidesWithItem(informatica)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            reto= new VReto;
            reto->setNum();
            reto->retoInfo();
            reto->show();
        }
    }
    else if(numNivel==3){
        if(estudiante->collidesWithItem(lecto)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            reto= new VReto;
            reto->setNum();
            reto->retoLecto();
            reto->show();
        }
        if(estudiante->collidesWithItem(english)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            reto= new VReto;
            reto->setNum();
            reto->retoE();
            reto->show();

        }
        else if(estudiante->collidesWithItem(mat)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            reto= new VReto;
            reto->setNum();
            reto->retoMat();
            reto->show();
        }
        else if(estudiante->collidesWithItem(informatica)){
            estudiante->setPos(15,450); //Reubicamos el jugador para evitar que detecte otra colision inmediatamente
            reto= new VReto;
            reto->setNum();
            reto->retoInfo();
            reto->show();
            //reto->close();
        }

    }
    //qDebug()<<"lleva: "<<numIntentos<< "intentos";

}
