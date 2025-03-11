#include <QApplication>
#include "dialog.h"
#include "vec2.h"

int main(int argc, char *argv[])
{
//    wtm::A  *a0 = new wtm::A;
//    wtm::A  *b0 = new wtm::B;

//    delete b0;
//    delete a0;

//    return 0;

    QApplication *a = new QApplication(argc, argv);

    Dialog dialog;
    dialog.show();

//    using Vec2 = wtm::Vec2T<double>;
//    using Vec2i = wtm::Vec2T<int>;
//    using Vec2f = wtm::Vec2T<float>;

//    Vec2   v0(0, 0);
//    Vec2   v1(1, 2);
//    Vec2   v2(-4, 3);
//    Vec2   v3(0.4, 0.4);
//    Vec2   v4(0.5, 0.5);

//    qDebug() << v0 + v1         // (1,2)
//             << v0 - v1         // (-1,-2)
//             << v1 * v2         // 2
//             << v1 * 2          // (2,4)
//             << v1 / 2          // (0.5,1)
//             << (v1 == v2)      // false
//             << (v1 < v2)       // false
//             << v1.norm()       // sqrt(5)
//             << v1.normSq()     // 5
//             << v2.normalised() // (-4/5,3/5)
//             << v3.almostEq(v4, 0.00001);

    return a->exec();
}
