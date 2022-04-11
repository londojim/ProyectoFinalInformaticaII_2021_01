#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include <ventana1.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;         //Se crea un atributo de clase MainWindow, y un apuntador ui a tipo MainWindow

    QGraphicsScene *scena;      //Se crea un objeto tipo escena para el inicio de1 juego
    /*
    QGraphicsScene *scenaN1;    //Se crea un objeto tipo escena para el nivel 1
    QGraphicsScene *scenaN2;    //Se crea un objeto tipo escena para el nivel 2
    */

};
#endif // MAINWINDOW_H
