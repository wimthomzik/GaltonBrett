#include "canvas.h"
#include "galtonboard.h"
#include <QPainter>
#include <QLayout>
#include <QBoxLayout>

Canvas::Canvas(QWidget *parent) : QWidget(parent), m_galtonBoard(new GaltonBoard(this))
{
    setLayout(new QHBoxLayout(this));
    Canvas::layout()->addWidget(m_galtonBoard);
}

