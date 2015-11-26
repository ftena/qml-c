#include "myclass.h"
#include <QDebug>
#include <QQuickItem>

MyClass::MyClass(QObject *obj)
{
    item = obj->findChild<QObject*>("mainButtonMouseArea");

    connect(item, SIGNAL(qmlSignal(QString, QVariant)),
            this, SLOT(cppSlot(QString, QVariant)));
}

void MyClass::cppSlot(const QString &msg, const QVariant &v) {
    qDebug() << "Called cppSlot:" << msg;

    QQuickItem *item =
               qobject_cast<QQuickItem*>(v.value<QObject*>());

    qDebug() << "Item dimensions:" << item->width()
             << item->height();
    qDebug() << "Item function hasActiveFocus:" << item->hasActiveFocus();
    qDebug() << "Item function hasFocus:" << item->hasFocus();

    qDebug() << "Item property activeFocus:" << item->property("activeFocus").toBool();
}

void MyClass::cppSlotInMain(const QString &msg) {
    qDebug() << "Called cppSlotInMain:" << msg;

}
