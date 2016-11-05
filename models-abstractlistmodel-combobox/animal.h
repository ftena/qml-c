#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>

class Animal
{
public:
    Animal(const QString &type, const QString &size);

    QString type() const;
    QString size() const;

private:
    QString m_type;
    QString m_size;
};

#endif // ANIMAL_H
