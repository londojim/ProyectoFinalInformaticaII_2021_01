#include "duscene.h"
#include "duball.h"
#include "duthread.h"

DuScene::DuScene(QObject *parent)
    :QGraphicsScene(XPOS,YPOS,XSIZE,YSIZE,parent)

{

    addRect(XPOS,YPOS,XSIZE,YSIZE);
}
