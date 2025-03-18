#include "dialog.h"
#include "ui_dialog.h"
#include "canvas.h"
#include "patterfactory.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->exitButton, &QPushButton::clicked, this, &Dialog::close);
    connect(ui->startButton, &QPushButton::clicked, ui->canvas, &Canvas::startSimulation);
    connect(ui->resetButton, &QPushButton::clicked, ui->canvas, &Canvas::resetSimulation);
    ui->patternNames->addItems(PatternFactory::Instance().names());
}

Dialog::~Dialog()
{
    delete ui;
}
