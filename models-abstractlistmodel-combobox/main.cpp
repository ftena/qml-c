#include "animalmodel.h"
#include "comboboxmanagement.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);

    AnimalModel model;
    model.addAnimal(Animal("Wolf", "Medium"));
    model.addAnimal(Animal("Polar bear", "Large"));
    model.addAnimal(Animal("Quoll", "Small"));

    ComboboxManagement comboboxManagement;
    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &model);    
    ctxt->setContextProperty("comboboxManagement", &comboboxManagement);

    engine.load(QUrl(QStringLiteral("qrc:/view.qml")));

    return app.exec();
}

