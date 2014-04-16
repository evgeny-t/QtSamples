#include "selectdaterangewidget.h"
#include "selectdatepopupwidget.h"

#include <QHBoxLayout>

SelectDateRangeWidget::SelectDateRangeWidget(QWidget *parent) :
    QWidget(parent)
{
    SelectDatePopupWidget *begin = new SelectDatePopupWidget(this);
    SelectDatePopupWidget *end = new SelectDatePopupWidget(this);

    layout = new QHBoxLayout(this);
    layout->addWidget(begin);
    layout->addWidget(end);
}
