#ifndef INGLESNIVEL1_H
#define INGLESNIVEL1_H

#include <QMainWindow>

namespace Ui {
class InglesNivel1;
}

class InglesNivel1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit InglesNivel1(QWidget *parent = nullptr);
    ~InglesNivel1();

    void setNum(int newNum);

private:
    Ui::InglesNivel1 *ui;
    int num;
    int contador;
};

#endif // INGLESNIVEL1_H
