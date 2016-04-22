#ifndef COMBOBOXMANAGEMENT_H
#define COMBOBOXMANAGEMENT_H

#include <QObject>
#include <QDebug>
#include "animalmodel.h"

class ComboboxManagement : public QObject
{
    Q_OBJECT
public:
    explicit ComboboxManagement(QObject *parent = 0);

    Q_INVOKABLE bool printValues(AnimalModel* model,
                               const QModelIndex &modelIndex);

};

#endif // COMBOBOXMANAGEMENT_H
