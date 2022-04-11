#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaje.h"
#include "estudiante.h"
#include <QGraphicsView>
#include <qgraphicsview.h>
//#define RUTA_EM "../PROYECTO FINAL/Imagenes/estudianteM.png"
const QString RUTA_EM = "../PROYECTO FINAL/Imagenes/estudianteM.png";



using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene();
    //Qpen lapiz1=;
    //brocha1=;
    escena->setSceneRect(0,0,800,600);
    ui->graphicsView->setScene(escena);


    escena->addRect(100,100,100,100);

    QImage estudianteM(RUTA_EM);
    QBrush b1(estudianteM);
    ui->graphicsView->setBackgroundBrush(b1);

    jugador = new Estudiante("Katherin",50,50,5);
    jugador->setRect(0,0,100,100);


    j = new Personaje("Katherin",50,50);
    j->setRect(0,0,100,100);

    jugador->boundingRect();
    //jugador->paint();
    escena->addItem(jugador);


    //Ventaja de inicio de sesion de usuario
    w1 = new QMainWindow();
    w1->show();
}

//Estudiante jugador1("Katherin",50,50,5);
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ventana1 *ventana = new ventana1;

    ventana->show();
}

