#include "filemanagement.h"

FileManagement::FileManagement(QObject *parent) : QObject(parent)
{

}

bool FileManagement::printPath(QFileSystemModel* fileSystemModel,
                       const QModelIndex &modelIndex) {
    qDebug() << "+ File path: " << fileSystemModel->filePath(modelIndex);
    return true;
}

bool FileManagement::printFileNames(QFileSystemModel* fileSystemModel,
                            QList<QModelIndex> modelIndexList) {
    qDebug() << "+ " << modelIndexList.size() << " items selected: ";
    QList<QModelIndex>::iterator i;
    for (i = modelIndexList.begin(); i != modelIndexList.end(); ++i) {
        qDebug() << "++ File name: " << fileSystemModel->fileName(*i);
    }

    return true;
}
