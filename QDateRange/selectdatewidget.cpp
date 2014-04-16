#include "selectdatewidget.h"

#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QCalendarWidget>
#include <QPushButton>
#include <QGridLayout>

SelectDateWidget::SelectDateWidget(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout;
    auto calendar = new QCalendarWidget(this);
    auto ok = new QPushButton("ОК", this);
    auto cancel = new QPushButton("Cancel", this);

    QObject::connect(ok, &QPushButton::clicked, [&]()
        {
            close();
            emit onOk(selectedDate());
        });

    QObject::connect(cancel, &QPushButton::clicked, [&]()
        {
            close();
        });

    layout->addWidget(calendar, 0, 0, 1, 2);
    layout->addWidget(ok, 1, 0);
    layout->addWidget(cancel, 1, 1);

    setLayout(layout);
    setWindowFlags(Qt::Popup);
    setFocus(Qt::PopupFocusReason);
    resize(150, 150);
}

QDate SelectDateWidget::selectedDate() const
{
    auto calendar = static_cast<QCalendarWidget*>(
                layout->itemAt(0)->widget());
    return calendar->selectedDate();
}

void SelectDateWidget::closeEvent(QCloseEvent *)
{
    qDebug("SelectDateWidget::closeEvent");
    qDebug() << selectedDate();
}

void SelectDateWidget::showEvent(QShowEvent *)
{
    auto screenSize = QApplication::desktop()->screen()->size();
    auto p = QCursor::pos();

    move(p);
    if (p.y() + size().height() > screenSize.height())
        move(p - QPoint(size().width(), size().height()));
}
