#include "comboboxmanagement.h"

ComboboxManagement::ComboboxManagement(QObject *parent) : QObject(parent)
{

}

bool ComboboxManagement::printValues(AnimalModel* model,
                       const QModelIndex &modelIndex) {
    qDebug() << model->data(modelIndex, AnimalModel::TypeRole);
    return true;
}
