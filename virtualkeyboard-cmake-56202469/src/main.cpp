#include <QQuickView>
#include <QGuiApplication>
#include <QQmlEngine>

int main(int argc, char** argv)
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);
    QQuickView view(QString("qrc:/main.qml"));

    if (view.status() == QQuickView::Error)
        return -1;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}

