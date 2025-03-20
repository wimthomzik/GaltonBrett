#include "dialog.h"
#include "ui_dialog.h"
#include "canvas.h"
#include "patternfactory.h"
#include "trianglepattern.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    PatternFactory::Instance().registerPattern(std::make_unique<TrianglePattern>());

    ui->setupUi(this);
    connect(ui->exitButton, &QPushButton::clicked, this, &Dialog::close);
    connect(ui->startButton, &QPushButton::clicked, ui->canvas, &Canvas::startSimulation);
    connect(ui->resetButton, &QPushButton::clicked, ui->canvas, &Canvas::resetSimulation);
    connect(ui->stopButton, &QPushButton::clicked, ui->canvas, &Canvas::stopSimulation);
    ui->patternNames->addItems(PatternFactory::Instance().names());
    connect(ui->patternNames, &QComboBox::currentTextChanged, ui->canvas, &Canvas::changePattern);
    ui->canvas->changePattern(QString("Triangle"));
}

Dialog::~Dialog()
{
    delete ui;
}
