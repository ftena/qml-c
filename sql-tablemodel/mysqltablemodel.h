#ifndef MYSQLTABLEMODEL_H
#define MYSQLTABLEMODEL_H

#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class MySqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    MySqlTableModel(QObject *parent = 0, QSqlDatabase db = QSqlDatabase());
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role=Qt::DisplayRole ) const;
    Q_INVOKABLE void addItem(const QString &name, const QString &salary);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QHash<int, QByteArray> roles;
};

#endif // MYSQLTABLEMODEL_H
