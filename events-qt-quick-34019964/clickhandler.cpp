#include "clickhandler.h"
#include <QQuickItem>

ClickHandler::ClickHandler(QObject *parent, QQmlApplicationEngine* engine, QGuiApplication* app) : QObject(parent)
{
    this->engine = engine;
    this->app = app;

}

void ClickHandler::handleClick()
{
    QObject* root = engine->rootObjects()[0];
    QQuickItem *item = (root->property("activeFocusItem")).value<QQuickItem *>();
    if (item == NULL)
        qDebug() << "NO item";

    Qt::Key key = Qt::Key_B;
    //QKeyEvent* event = new QKeyEvent(QKeyEvent::KeyPress, key, Qt::NoModifier);    
    QKeyEvent* event = new QKeyEvent(QKeyEvent::KeyPress,
                                     key,
                                     Qt::NoModifier,
                                     QKeySequence(key).toString());
    QCoreApplication::postEvent(item,event);
}
