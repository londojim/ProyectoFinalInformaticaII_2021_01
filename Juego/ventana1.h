#ifndef VENTANA1_H
#define VENTANA1_H
#include <QPixmap>
#include <QDialog>
#include<QGraphicsItem>
#include<QPainter>


using namespace std;


namespace Ui {
class ventana1;
}

class ventana1 : public QDialog
{
    Q_OBJECT

public:


    explicit ventana1(QWidget *parent = nullptr);
    ~ventana1();

private:
    Ui::ventana1 *ui;
};

#endif // VENTANA1_H
