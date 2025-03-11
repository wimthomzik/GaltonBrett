#ifndef PIN_H
#define PIN_H

#include <staticgraphicalprimitive.h>

class Pin : public StaticGraphicalPrimitive
{
public:
    explicit Pin() = default;
    explicit Pin(QPointF position, QSizeF size, QRectF boundingBox);

    void draw() override;
};

#endif // PIN_H
