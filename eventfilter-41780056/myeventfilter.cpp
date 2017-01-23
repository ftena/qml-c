#include "myeventfilter.h"
#include <QEvent>
#include <QDebug>

MyEventFilter::MyEventFilter(QObject *parent) :
    QObject(parent)
{
}

bool MyEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Close)
    {
        qDebug() << Q_FUNC_INFO << " QEvent::Close ";
        return false;
    } else if (event->type() == QEvent::WindowStateChange)
    {
        qDebug() << Q_FUNC_INFO << " QEvent::WindowStateChange ";
        emit windowStateChange();
        return true;
    } else
    {
        return QObject::eventFilter(obj, event);
    }
}

