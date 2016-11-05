#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mysqltablemodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb");

    if(!db.open()) {
        qDebug() << db.lastError().text();
        return 0;
    }

    QSqlQuery query(db);

    if(!query.exec("DROP TABLE IF EXISTS mytable")) {
        qDebug() << "create table error: " << query.lastError().text();
        return 0;
    }

    if(!query.exec("CREATE TABLE IF NOT EXISTS mytable \
                   (id integer primary key autoincrement, name varchar(15), salary integer)")) {
        qDebug() << "create table error: " << query.lastError().text();
        return 0;
    }

    MySqlTableModel *model = new MySqlTableModel(0, db);
    model->setTable("mytable");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    QSqlRecord rec = model->record();
    rec.setValue(1, "peter");
    rec.setValue(2, 100);
    model->insertRecord(-1, rec);
    rec.setValue(1, "luke");
    rec.setValue(2, 200);
    model->insertRecord(-1, rec);

    if(model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        qDebug() << "database error: " << model->lastError().text();
    }

    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
