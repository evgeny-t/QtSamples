#include "selectdaterangewidget.h"
#include "selectdatewidget.h"

#include <QHBoxLayout>

SelectDateRangeWidget::SelectDateRangeWidget(QWidget *parent) :
    QWidget(parent)
{
    SelectDateWidget *first = new SelectDateWidget(this),
            *second = new SelectDateWidget(this);

    layout = new QHBoxLayout;
    layout->addWidget(first);
    layout->addWidget(second);

    resize(300, 41);
    setLayout(layout);
}

QPair<QDate, QDate> SelectDateRangeWidget::range() const
{
    QWidget *first = layout->itemAt(0)->widget(),
            *second = layout->itemAt(1)->widget();
    return qMakePair(
                static_cast<SelectDateWidget*>(first)->date(),
                static_cast<SelectDateWidget*>(second)->date());
}
