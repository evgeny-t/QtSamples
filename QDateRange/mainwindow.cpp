#include "mainwindow.h"

#include <QDebug>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    selectrange = new SelectDateRangeWidget(this);
    resize(400, 400);
}

MainWindow::~MainWindow()
{

}
