#ifndef GALTONBOARD_H
#define GALTONBOARD_H

#include <ball.h>
#include <QWidget>
#include <QVector>
#include <ball.h>
#include <wall.h>
#include <pin.h>
#include <QElapsedTimer>

class GaltonBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GaltonBoard(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

private:
    QElapsedTimer *elapsedTimer;
    //Ball ball;
    //QVector<Ball> walls;
    QVector<QRect> pins;

};

#endif // GALTONBOARD_H
