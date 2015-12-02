#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QObject>

class CustomItem: public QObject
{
    Q_OBJECT

    /*
     * Any property that is writable should have an associated NOTIFY signal.
     * Ref: http://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html#exposing-properties
     */

    Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)

public:
    CustomItem(QObject *parent = 0);

    int size() const;
    void setSize(int);

    Q_INVOKABLE void mouseClick();

private:
    int m_size;

signals:
    void sizeChanged(int size);
    void clicked();

public slots:
};

#endif // CUSTOMITEM_H
