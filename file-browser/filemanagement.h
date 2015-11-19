#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <QObject>
#include <QDebug>
#include <QFileSystemModel>

class FileManagement : public QObject
{
    Q_OBJECT
public:
    explicit FileManagement(QObject *parent = 0);

    Q_INVOKABLE bool printPath(QFileSystemModel* fileSystemModel,
                               const QModelIndex &modelIndex);

    Q_INVOKABLE bool printFileNames(QFileSystemModel* fileSystemModel,
                                    QList<QModelIndex> modelIndexList);

signals:

public slots:

    void test() {
        qDebug() << "Called the C++ slot";
    }
};

#endif // FILEMANAGEMENT_H
