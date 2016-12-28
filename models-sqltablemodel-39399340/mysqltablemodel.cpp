#include "mysqltablemodel.h"

MySqlTableModel::MySqlTableModel(QObject *parent, QSqlDatabase db): QSqlTableModel(parent, db) {}

QVariant MySqlTableModel::data ( const QModelIndex & index, int role ) const
{
    if(index.row() >= rowCount()) {
        return QString("");
    }
    if(role < Qt::UserRole) {
        return QSqlQueryModel::data(index, role);
    }
    else {
        return QSqlQueryModel::data(this->index(index.row(), role - Qt::UserRole), Qt::DisplayRole);
    }
}

QHash<int, QByteArray> MySqlTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "name";
    roles[Qt::UserRole + 2] = "salary";
    return roles;
}

void MySqlTableModel::addItem(const QString &name, const QString &salary)
{
    QSqlRecord rec = this->record();
    rec.setValue(1, name);
    rec.setValue(2, salary.toInt());
    this->insertRecord(-1, rec);

    if(this->submitAll()) {
        this->database().commit();
    } else {
        this->database().rollback();
        qDebug() << "database error: " << this->lastError().text();
    }
}
