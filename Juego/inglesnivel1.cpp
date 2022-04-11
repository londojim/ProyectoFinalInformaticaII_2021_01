#include "inglesnivel1.h"
#include "ui_inglesnivel1.h"

InglesNivel1::InglesNivel1()
{

}


InglesNivel1::InglesNivel1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InglesNivel1)
{
    ui->setupUi(this);
    contador=0;
}

InglesNivel1::~InglesNivel1()
{
    delete ui;
}

void Ventana2::setNum(int newNum)
{
    num = newNum;
    contador++;
    ui->lcdNumber->display(newNum);
    ui->lcdNumber_2->display(contador);
}
