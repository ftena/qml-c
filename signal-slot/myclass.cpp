#include "myclass.h"
#include <QDebug>
#include <QQuickItem>
#include <QQuickWindow>

MyClass::MyClass(QObject *obj)
{
    item = obj->findChild<QObject*>("mainButtonMouseArea");
    mainWindow = obj;

    connect(item, SIGNAL(qmlItemDataSignal(QString, QVariant)),
            this, SLOT(cppItemDataSlot(QString, QVariant)));

    connect(obj, SIGNAL(qmlWindowDataSignal(QVariant)),
            this, SLOT(cppWindowDataSlot(QVariant)));
}

void MyClass::cppItemDataSlot(const QString &msg, const QVariant &v) {
    qDebug() << "*** Called cppSlot:" << msg;

    QQuickItem *item =
               qobject_cast<QQuickItem*>(v.value<QObject*>());

    qDebug() << "Item dimensions:" << item->width()
             << item->height();
    qDebug() << "Item function hasActiveFocus:" << item->hasActiveFocus();
    qDebug() << "Item function hasFocus:" << item->hasFocus();

    qDebug() << "Item property activeFocus:" <<
                item->property("activeFocus").toBool();
    qDebug() << "Item property activeFocusItem:" <<
                item->property("activeFocusItem").toBool();
}

void MyClass::cppWindowDataSlot(const QVariant &v) {
        qDebug() << "*** Called cppWindowDataSlot";

    QQuickWindow *w = (QQuickWindow*) mainWindow;

    qDebug() << "activeFocus value using QQuickWindow:" <<
                w->activeFocusItem()->property("activeFocus").toBool();
    qDebug() << "objectName value using QQuickWindow:" <<
                w->activeFocusItem()->property("objectName").toString();

    QQuickItem *wi = w->property("activeFocusItem").value<QQuickItem*>();

    qDebug() << "activeFocus value using QQuickItem:" <<
                wi->property("activeFocus").toBool();
    qDebug() << "text value using QQuickItem:" <<
                wi->property("text").toString();

    QQuickWindow *item = qobject_cast<QQuickWindow*>(v.value<QObject*>());

    qDebug() << "width value using QQuickWindow & QVariant:" <<
                item->activeFocusItem()->property("width").toString();
}

void MyClass::cppSlotInMain(const QString &msg) {
    qDebug() << "*** Called cppSlotInMain:" << msg;
}
