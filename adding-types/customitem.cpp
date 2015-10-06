#include "customitem.h"

CustomItem::CustomItem(QObject *parent)
: QObject(parent), m_x(0), m_y(0)
{
}

int CustomItem::x() const
{
    return m_x;
}

void CustomItem::setX(int x)
{
    m_x = x;
}

int CustomItem::y() const
{
    return m_y;
}

void CustomItem::setY(int y)
{
    m_y = y;
}

