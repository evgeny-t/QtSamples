#include "selectdatewidget.h"
#include "selectdatepopupwidget.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>

class SelectDateWidgetImp
{
public:
    QHBoxLayout *layout;
    QPushButton *button;
    QTextEdit *textedit;
    QDate selectedDate;
};

SelectDateWidget::SelectDateWidget(QWidget *parent) :
    QWidget(parent)
{
    imp = new SelectDateWidgetImp;
    imp->layout = new QHBoxLayout;
    imp->button = new QPushButton(this);
    imp->textedit = new QTextEdit(this);

    imp->layout->addWidget(imp->textedit);
    imp->layout->addWidget(imp->button);

    QObject::connect(imp->button, &QPushButton::clicked, [&]()
        {
            SelectDatePopupWidget *sdwidget = new SelectDatePopupWidget(this);
            QObject::connect(sdwidget, &SelectDatePopupWidget::onOk, [&](QDate date)
                {
                    imp->textedit->setText(date.toString());
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
