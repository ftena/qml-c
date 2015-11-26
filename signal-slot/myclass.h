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

public slots:
    void cppSlot(const QString &msg, const QVariant &v);
    void cppSlotInMain(const QString &msg);
};

#endif // MYCLASS_H
