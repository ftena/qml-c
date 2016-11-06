#include "animalmodel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include <qqml.h>

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);

    AnimalModel model;
    model.addAnimal("Wolf", "Medium");
    model.addAnimal("Polar bear", "Large");
    model.addAnimal("Quoll", "Small");

    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:/view.qml")));

    return app.exec();
}

