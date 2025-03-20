#include <QApplication>
#include "dialog.h"
#include "vec2.h"

int main(int argc, char *argv[])
{
    QApplication *a = new QApplication(argc, argv);

    Dialog dialog;
    dialog.show();

    return a->exec();
}
