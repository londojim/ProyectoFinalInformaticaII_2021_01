#ifndef DUBALL_H
#define DUBALL_H

#include <QGraphicsItem>

class DuBall : public QGraphicsItem {
private:
  double m_pos_x;
  double m_pos_y;
  double m_width;
  double m_height;

protected:
   QRectF boundingRect() const override;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

public:
  DuBall(double x, double y, double w, double h,QGraphicsItem *parent = nullptr);

  double pos_x() const;
  void setPos_x(double newPos_x);

  double pos_y() const;
  void setPos_y(double newPos_y);

  double width() const;
  void setWidth(double newWidth);

  double height() const;
  void setHeight(double newHeight);
};

#endif // DUBALL_H
