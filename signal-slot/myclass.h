#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

public:
    MyClass(QObject *obj);

private:
    QObject *item;
    QObject *mainWindow;

public slots:
    void cppItemDataSlot(const QString &msg, const QVariant &v);
    void cppWindowDataSlot(const QVariant &v);
    void cppSlotInMain(const QString &msg);
};

#endif // MYCLASS_H
