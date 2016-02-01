// main cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myclass.h"

int main(int argc, char *argv[])
{
     QGuiApplication app(argc, argv);

     QQmlApplicationEngine engine;
     engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
     QObject *item = engine.rootObjects().first();

     MyClass myClass;
     QObject::connect(item, SIGNAL(qmlSignal(QString)),
                      &myClass, SLOT(cppSlot(QString)));

     return app.exec();
}
