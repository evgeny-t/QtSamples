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
