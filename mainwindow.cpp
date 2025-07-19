
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rec = new RectangleWidget();
    ui->centralwidget->layout()->addWidget(rec);

    circle = new CircleWidget();
    ui->centralwidget->layout()->addWidget(circle);
}

MainWindow::~MainWindow()
{
    delete rec;
    delete circle;
    delete ui;
}


