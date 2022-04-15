#ifndef BOTON_H
#define BOTON_H
#include<QGraphicsRectItem>
#include<QGraphicsSceneMouseEvent>

class Boton: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    Boton(QString nombreB, QGraphicsItem * parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
signals:
    void click();
private:
    QGraphicsTextItem *text ;
};
#endif // BOTON_H
