#ifndef WALL_H
#define WALL_H

#include <staticgraphicalprimitive.h>

class Wall : public StaticGraphicalPrimitive
{
public:
    explicit Wall() = default;
    explicit Wall(QPointF position, QSizeF size, QRectF boundingBox);

    void draw() override;
};

#endif // WALL_H
