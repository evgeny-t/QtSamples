#include "mainwindow.h"

#include <QDebug>
#include <QDate>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SelectDateRangeWidget *selectrange =
            new SelectDateRangeWidget(this);

    layout = new QVBoxLayout;
    layout->addWidget(selectrange);

    auto button = new QPushButton(this);
    auto label = new QLabel(this);

    QObject::connect(button, &QPushButton::clicked, [label, selectrange](bool)
        {
            QPair<QDate, QDate> range = selectrange->range();
            label->setText(QString("%1 %2")
                           .arg(range.first.toString())
                           .arg(range.second.toString()));
        });

    layout->addWidget(button);
    layout->addWidget(label);

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(layout);
    resize(400, 400);
}

MainWindow::~MainWindow()
{

}
