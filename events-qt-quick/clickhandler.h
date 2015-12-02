#ifndef CLICKHANDLER_H
#define CLICKHANDLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QGuiApplication>

class ClickHandler : public QObject
{
    Q_OBJECT
    QQmlApplicationEngine* engine;
    QGuiApplication* app;

public:
    explicit ClickHandler(QObject *parent, QQmlApplicationEngine *,QGuiApplication* app);

signals:

public slots:
    void handleClick();
};

#endif // CLICKHANDLER_H
