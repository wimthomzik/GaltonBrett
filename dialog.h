#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "canvas.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    Canvas *m_canvas;
};

#endif // DIALOG_H
