#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaje.h"
#include "estudiante.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Estudiante jugador1("Katherin",50,50,5);









MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ventana1 *ventana = new ventana1;

    ventana->show();
}

