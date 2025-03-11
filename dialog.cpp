#include "dialog.h"
#include "ui_dialog.h"
#include "canvas.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)/*, m_canvas(new Canvas(this))*/
{
    ui->setupUi(this);
    connect(ui->exitButton, &QPushButton::clicked, this, &Dialog::close);
}

Dialog::~Dialog()
{
    delete ui;
}
