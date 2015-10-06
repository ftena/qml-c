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

    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)


public:
    CustomItem(QObject *parent = 0);

    int x() const;
       void setX(int);

       int y() const;
       void setY(int);

private:
    int m_x;
    int m_y;

signals:
    void xChanged();
    void yChanged();

public slots:
};

#endif // CUSTOMITEM_H
