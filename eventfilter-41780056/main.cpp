#include <QApplication>
#include <QQmlApplicationEngine>
#include "myeventfilter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyEventFilter filter;

    QQmlApplicationEngine engine;
    app.installEventFilter(&filter);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject::connect(&filter,
                     SIGNAL(windowStateChange()),
                     engine.rootObjects().takeFirst(),
                     SLOT(windowStateChange()));

    return app.exec();
}
