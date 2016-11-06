#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H

#include <QStandardItemModel>

class AnimalModel : public QStandardItemModel
{
    Q_OBJECT
public:
    enum AnimalRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    AnimalModel(QObject *parent = 0);

    Q_INVOKABLE void addAnimal(const QString &type, const QString &size);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
};

#endif // ANIMALMODEL_H
