#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QObject>

class MyEventFilter : public QObject
{
    Q_OBJECT

public:
    explicit MyEventFilter(QObject *parent = 0);

protected:
     bool eventFilter(QObject *obj, QEvent *event);

signals:
  void windowStateChange();
};

#endif // MYEVENTFILTER_H
