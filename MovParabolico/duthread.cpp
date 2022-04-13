#include "duthread.h"

DuThread::DuThread(int milisegundo, QObject *parent) : QThread(parent) {
  m_miliseconds = milisegundo;
}

void DuThread::run() {
  while (true) {
    msleep(m_miliseconds);
    emit timeOut();
  }
}
