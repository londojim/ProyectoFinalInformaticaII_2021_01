#include "ventana1.h"
#include "ui_ventana1.h"

ventana1::ventana1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventana1)
{
    ui->setupUi(this);

    //QPixmap  pxmap(":/imagenes/SalonIngles1.jpg");
    //painter->drawPixmap(boungingRect(),pxmap,pxmap.rect())
}

ventana1::~ventana1()
{
    delete ui;
}
