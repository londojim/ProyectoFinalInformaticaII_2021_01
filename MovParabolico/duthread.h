#ifndef DUTHREAD_H
#define DUTHREAD_H

#include <QThread>

class DuThread : public QThread {
    Q_OBJECT
public:
  DuThread(int milisegundo, QObject *parent = nullptr);

signals:
  void timeOut();


protected:
  void run() override;

private:
  int m_miliseconds;

};

#endif // DUTHREAD_H
