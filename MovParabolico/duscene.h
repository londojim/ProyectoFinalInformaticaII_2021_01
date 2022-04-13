 #ifndef DUSCENE_H
#define DUSCENE_H

#include <QGraphicsScene>
#include <QVector>//stl


#define XPOS 0.0 //LEFT DEL RECTANGULO
#define YPOS 0.0//TOP DEL RECTANGULO
#define XSIZE 600.0//WIDTH DEL RECTANGULO
#define YSIZE 600.0//HEIGHT   DEL RECTANGULO
#define MILISENCONDS 1

class DuBall;
class DuThread;

class DuScene : public QGraphicsScene {
    Q_OBJECT

public:
  DuScene(QObject *parent = nullptr);

  void startScene();


private:
  QVector<QPointF> calculatePath() const;
  int m_index;
  DuBall *m_ball;
  DuThread *m_thread;
  QVector<QPointF> m_path;
};

#endif // DUSCENE_H
