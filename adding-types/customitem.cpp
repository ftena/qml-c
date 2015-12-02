#include "customitem.h"
#include <QDebug>

CustomItem::CustomItem(QObject *parent)
: QObject(parent), m_size(0)
{
}

int CustomItem::size() const
{
    return m_size;
}

void CustomItem::setSize(int size)
{
    m_size = size;
    emit sizeChanged(m_size);
}

void CustomItem::mouseClick()
{
    qDebug() << "CustomItem::mouseClick()";

    emit clicked();
}

