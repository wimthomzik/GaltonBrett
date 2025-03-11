#ifndef CANVAS_H
#define CANVAS_H

#include <QPainter>
#include <galtonboard.h>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

private:
    GaltonBoard *m_galtonBoard;
};



#endif // CANVAS_H
