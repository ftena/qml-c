#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *rootObj = engine.rootObjects().first();
    QObject *item = rootObj->findChild<QObject*>("mainButtonMouseArea");

    MyClass myClass(rootObj);

    QObject::connect(item, SIGNAL(qmlSignalMain(QString)),
                         &myClass, SLOT(cppSlotInMain(QString)));

    return app.exec();
}
