 #ifndef DUSCENE_H
#define DUSCENE_H

#include <QGraphicsScene>

#define XPOS 0.0 //LEFT DEL RECTANGULO
#define YPOS 0.0//TOP DEL RECTANGULO
#define XSIZE 600.0//WIDTH DEL RECTANGULO
#define YSIZE 600.0//HEIGHT   DEL RECTANGULO


class DuBall;
class DuThread;

class DuScene : public QGraphicsScene {
public:
  DuScene(QObject *parent = nullptr);

private:
  DuBall *m_ball;
  DuThread *m_thread;

};

#endif // DUSCENE_H
