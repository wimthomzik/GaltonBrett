#include "graphicalprimitive.h"

GraphicalPrimitive::GraphicalPrimitive(QPointF position, QSizeF size, QRectF boundingBox)
    : m_position(position), m_size(size), m_boundingBox(boundingBox) {}

void GraphicalPrimitive::setPosition(const QPointF &newPosition)
{
   m_position = newPosition;
}

void GraphicalPrimitive::setSize(const QSizeF newSize)
{
   m_size = newSize;
}

QSizeF GraphicalPrimitive::getSize() const
{
   return m_size;
}
