#include "selectdatewidget.h"

#include <QApplication>
#include <QDesktopWidget>

#include <QCalendarWidget>
#include <QPushButton>
#include <QGridLayout>

SelectDateWidget::SelectDateWidget(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout(this);
    auto calendar = new QCalendarWidget(this);
    auto ok = new QPushButton("ОК", this);
    auto cancel = new QPushButton("Отмена", this);

    QObject::connect(ok, &QPushButton::clicked, [&]()
        {
            close();
        });

    QObject::connect(cancel, &QPushButton::clicked, [&]()
        {
            close();
        });

    layout->addWidget(calendar, 0, 0, 1, 2);
//    layout->setRowMinimumHeight(0, calendar->height());
//    layout->setColumnMinimumWidth(0, calendar->width());
    layout->addWidget(ok, 1, 0);
    layout->addWidget(cancel, 1, 1);

    setWindowFlags(Qt::Popup);

    setFocus(Qt::PopupFocusReason);


    resize(250, 250);
}

void SelectDateWidget::closeEvent(QCloseEvent *)
{
    qDebug("SelectDateWidget::closeEvent");
}

void SelectDateWidget::showEvent(QShowEvent *)
{
    auto screenSize = QApplication::desktop()->screen()->size();
    auto p = QCursor::pos();

    move(p);
    if (p.y() + size().height() > screenSize.height())
        move(p - QPoint(size().width(), size().height()));
}
