#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include "clickhandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* root = engine.rootObjects()[0];
    ClickHandler* ch = new ClickHandler(root, &engine, &app);
    QQuickItem* button = root->findChild<QQuickItem*>("button");

    QObject::connect(button, SIGNAL(clicked()), ch, SLOT(handleClick()));

    return app.exec();
}

