#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "customitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<CustomItem>("CustomItem", 1,0, "CustomItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

