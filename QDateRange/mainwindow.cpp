#include "mainwindow.h"
#include "selectdatepopupwidget.h"

#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new QWidget(this));

    layout = new QHBoxLayout(centralWidget());
    button = new QPushButton(this);
    textedit = new QTextEdit(this);

    layout->addWidget(textedit);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [&]()
        {
            SelectDatePopupWidget *sdwidget = new SelectDatePopupWidget(this);
            QObject::connect(sdwidget, &SelectDatePopupWidget::onOk, [&](QDate date)
                {
                    textedit->setText(date.toString());
                });
            sdwidget->show();
        });

    resize(400, 400);

    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{

}
