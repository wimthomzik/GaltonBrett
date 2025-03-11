#ifndef CANVAS_H
#define CANVAS_H

#include <QPainter>
#include <galtonboard.h>
#include <vec2.h>
#include <QWheelEvent>

using Vec2 = wtm::Vec2T<double>;

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

private:
    GaltonBoard *m_galtonBoard;
    Vec2 m_offset;
    Vec2 m_prevPos;
    Vec2 m_scale {1, -1};
};

#endif // CANVAS_H
