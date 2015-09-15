#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QObject *obj)
{
    QObject *item = obj->findChild<QObject*>("mainButtonMouseArea");

    connect(item, SIGNAL(qmlSignal(QString)),
            this, SLOT(cppSlot(QString)));
}

void MyClass::cppSlot(const QString &msg) {
    qDebug() << "Called cppSlot:" << msg;
}

void MyClass::cppSlotInMain(const QString &msg) {
    qDebug() << "Called cppSlotInMain:" << msg;
}
