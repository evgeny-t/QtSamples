#include "selectdatewidget.h"
#include "selectdatepopupwidget.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QDateEdit>

class SelectDateWidgetImp
{
public:
    QHBoxLayout *layout;
    QPushButton *button;
    QDateEdit *edit;
    QDate selectedDate;
};

SelectDateWidget::SelectDateWidget(QWidget *parent) :
    QWidget(parent)
{
    imp = new SelectDateWidgetImp;
    imp->layout = new QHBoxLayout;
    imp->button = new QPushButton(this);
    imp->edit = new QDateEdit(this);
    imp->edit->setEnabled(false);

    imp->layout->addWidget(imp->edit);
    imp->layout->addWidget(imp->button);

    QObject::connect(imp->button, &QPushButton::clicked, [&]()
        {
            SelectDatePopupWidget *sdwidget = new SelectDatePopupWidget(this);
            QObject::connect(sdwidget, &SelectDatePopupWidget::onOk, [&](QDate date)
                {
                    imp->edit->setDate(date);
                    imp->selectedDate = date;
                });
            sdwidget->show();
        });

    this->setLayout(imp->layout);

    setMinimumSize(150, 41);
//    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

SelectDateWidget::~SelectDateWidget()
{
    delete imp;
}

QDate SelectDateWidget::date() const
{
    return imp->selectedDate;
}
