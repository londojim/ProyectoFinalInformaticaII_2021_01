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

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    musica = new QMediaPlayer();

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    numNivel=3;     //Añadir validación nota...
}


void Game::menu()
{
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":imagenes/fuente.jpg")));

    musica->setMedia(QUrl("qrc:/s/menu.mp3"));
    musica->play();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Salvando el semestre"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);

    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // crear boton play
    Boton * playButton = new Boton(QString("Jugar"));
    int bxPos = 70;//this->width()/2 -playButton->boundingRect().width()/2
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(click()),this,SLOT(start()));
    scene->addItem(playButton);

    // crear boton salir
    Boton * quitButton = new Boton(QString("Salir"));
    int qxPos = 65;//this->width()/2 -quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(playButton,SIGNAL(click()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void Game::start()
{
    //Musica de fondo
    musica->setMedia(QUrl("qrc:/s/Fondo.mp3"));
    musica->play();

    QTimer *timer = new QTimer();
    QTimer *timer1 = new QTimer();
    nota = new Puntaje();

    if(numNivel==1){

        //PINTANDO LA ESCENA NIVEL 1
        scene->clear();
        setBackgroundBrush(QBrush(QImage(":/imagenes/bloqueING.png")));
        setScene(scene);    //Para poder visualizar la escena
        scene->addItem(nota);
        scene->addText("Nivel 1")->setPos(400,0);//->setFont(QFont("Trajan Pro",20));

        //CREACIÓN JUGADOR
        estudiante = new Jugador();
        estudiante->setPos(150,500);
        estudiante->setPixmap(QPixmap(":/imagenes/estudianteH.png"));
        //Movimiento del jugador
        estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
        estudiante->setFocus();
        scene ->addItem(estudiante);

        //*CREACIÓN DISTRACTORES
        consola = new Distractor();
        consola->setPos(360,175);
        scene->addItem(consola);

        consola2 = new Distractor();
        consola2->setPos(500,450);
        scene->addItem(consola2);

        amigo = new AmigoD();
        amigo->setPos(675,500);
        scene->addItem(amigo);
        //DISPAROS DE AMIGO
        QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
        timer->start(5000);

        //CREACIÓN ASIGNATURAS
        lecto = new Asignaturas();
        lecto->setPos(200,300);
        scene->addItem(lecto);

        english = new Asignaturas();
        english->setPos(550,220);
        scene->addItem(english);

        show();

    }
    if(numNivel==2){
        //PINTANDO LA ESCENA NIVEL 2/
        scene->clear();
        setBackgroundBrush(QBrush(QImage(":/imagenes/biblioteca.png")));
        setScene(scene);    //Para poder visualizar la escena
        scene->addText("Nivel 2")->setPos(400,0);//->setFont(QFont("Trajan Pro",20));
        scene->addItem(nota);

        //CREACIÓN JUGADOR
        estudiante = new Jugador();
        estudiante->setPos(150  ,500);
        estudiante->setPixmap(QPixmap(":/imagenes/estudianteM.png"));
       //Movimiento del jugador
        estudiante->setFlag(QGraphicsItem::ItemIsFocusable);
        estudiante->setFocus();
        scene->addItem(estudiante);

        //CREACIÓN DISTRACTORES
        amigo = new AmigoD();
        amigo->setPos(675,500);
        scene->addItem(amigo);

        QObject::connect(timer, SIGNAL(timeout()),amigo, SLOT(Disparar()));
        timer->start(3000);

        consola = new Distractor();
        consola->setPos(350,300);
        scene->addItem(consola);

        //***********CREACIÓN ASIGNATURAS***************
        mat = new Asignaturas();
        mat->setPos(85,180);
        scene->addItem(mat);

        english = new Asignaturas();
        english->setPos(350,100);
        scene->addItem(english);

        informatica = new Asignaturas();
        informatica->setPos(600,50);
        scene->addItem(informatica);

        /*if(estudiante->collidesWithItem(mat)) {
            musica->stop();
            VReto *vIngles = new VReto;
            vIngles->show();
        }*/
        show();
    }
    if(numNivel==3){
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
        consola->setPos(350,300);
        scene->addItem(consola);

        //***********CREACIÓN ASIGNATURAS***************
        mat = new Asignaturas();
        mat->setPos(350,480);
        scene->addItem(mat);

        english = new Asignaturas();
        english->setPos(350,100);
        scene->addItem(english);

        informatica = new Asignaturas();
        informatica->setPos(600,50);
        scene->addItem(informatica);

        lecto = new Asignaturas();
        lecto->setPos(150,300);
        scene->addItem(lecto);
    }

}
