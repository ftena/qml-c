#include <QGuiApplication>
#include <QStringList>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);

    QStringList s;
    s.append("1");
    s.append("2");
    s.append("2");
    s.append("2");
    s.append("2");
    s.append("3");

    QQuickView view;

    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(s));

    view.setSource(QUrl("qrc:view.qml"));
    view.show();

    return app.exec();
}
