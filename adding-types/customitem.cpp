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

    /*To prevent loops or excessive evaluation, developers should ensure that
     * the property change signal is only emitted when the property value has
     * actually changed.
     * Also, if a property or group of properties is infrequently used,
     * it is permitted to use the same NOTIFY signal for several properties.
     * This should be done with care to ensure that performance doesn't
     * suffer.
    */
    emit sizeChanged(m_size);
}

void CustomItem::mouseClick()
{
    qDebug() << this << " - CustomItem::mouseClick()";

    emit clicked();
}

void CustomItem::test()
{
    qDebug() << this << " - CustomItem::text()";
}

