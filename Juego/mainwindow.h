#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qgraphicsview.h>
#include <string>

#include <QKeyEvent>


#include <QList>
#include <QTimer>


#include <ventana1.h>

#include <personaje.h>
#include <estudiante.h>
#include <profesor.h>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void keyPressEvent(QKeyEvent *e);



private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;         //Se crea un atributo de clase MainWindow, y un apuntador ui a tipo MainWindow
    QGraphicsScene *escena;      //Se crea un objeto tipo escena

    Estudiante *jugador;
    Personaje *j;

    QMainWindow *w1;   //Apuntador a la ventana de inicio
    QMainWindow *i;   //Apuntador a la ventana de inglés

};
#endif // MAINWINDOW_H
