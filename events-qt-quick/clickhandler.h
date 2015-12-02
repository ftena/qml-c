#ifndef CLICKHANDLER_H
#define CLICKHANDLER_H

#include <QObject>

class ClickHandler : public QObject
{
    Q_OBJECT
public:
    explicit ClickHandler(QObject *parent = 0);

signals:

public slots:
};

#endif // CLICKHANDLER_H
