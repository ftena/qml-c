#include "animalmodel.h"

AnimalModel::AnimalModel(QObject *parent)
    : QStandardItemModel(parent)
{

}

void AnimalModel::addAnimal(const QString &type, const QString &size)
{
    QStandardItem* entry = new QStandardItem();
    entry->setData(type, TypeRole);

    auto childEntry = new QStandardItem();
    childEntry->setData(size, SizeRole);
    entry->appendRow(childEntry);

    appendRow( entry );
}

QVariant AnimalModel::data(const QModelIndex & index, int role) const {
    QStandardItem *myitem = itemFromIndex(index);

    if (role == TypeRole)
        return myitem->data(TypeRole);
    else if (role == SizeRole) {
        if (myitem->child(0) != 0)
        {
            return myitem->child(0)->data(SizeRole);
        }
    }

    return QVariant();
}

QHash<int, QByteArray> AnimalModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}
