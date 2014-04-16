#include "selectdaterangewidget.h"
#include "selectdatewidget.h"

#include <QHBoxLayout>

SelectDateRangeWidget::SelectDateRangeWidget(QWidget *parent) :
    QWidget(parent)
{
    SelectDateWidget *begin = new SelectDateWidget(this);
    SelectDateWidget *end = SelectDateWidget(this);

    layout = QHBoxLayout(this);
    layout->addWidget(begin);
    layout->addWidget(end);
}
