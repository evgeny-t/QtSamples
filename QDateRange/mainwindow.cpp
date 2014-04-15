#include "mainwindow.h"
#include "selectdatewidget.h"

#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    button = new QPushButton(this);
    QObject::connect(button, &QPushButton::clicked, [&]()
        {
            SelectDateWidget *sdwidget = new SelectDateWidget(this);
            sdwidget->show();
        });

    resize(400, 400);
}

MainWindow::~MainWindow()
{

}
