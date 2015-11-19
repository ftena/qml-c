#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QFileSystemModel>
#include "filemanagement.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FileManagement fileManagement;
    QQmlApplicationEngine engine;
    QFileSystemModel *fsm = new QFileSystemModel(&engine);
    fsm->setRootPath(QDir::homePath());
    fsm->setResolveSymlinks(true);
    engine.rootContext()->setContextProperty("fileManagement", &fileManagement);
    engine.rootContext()->setContextProperty("fileSystemModel", fsm);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}

