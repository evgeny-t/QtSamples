#ifndef SELECTDATEWIDGET_H
#define SELECTDATEWIDGET_H

#include <QWidget>
#include <QDate>

class SelectDateWidgetImp;

class SelectDateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SelectDateWidget(QWidget *parent = 0);
    ~SelectDateWidget();
    QDate date() const;

signals:
public slots:
private:
    SelectDateWidgetImp *imp;
};

#endif // SELECTDATEWIDGET_H
