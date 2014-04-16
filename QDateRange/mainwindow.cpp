#include "mainwindow.h"

#include <QDebug>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    selectrange = new SelectDateRangeWidget(this);
//    selectrange->resize(400, 200);

//    setCentralWidget(new QWidget(this));

    resize(400, 400);

//    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{

}
