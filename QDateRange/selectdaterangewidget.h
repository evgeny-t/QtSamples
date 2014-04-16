#ifndef SELECTDATERANGEWIDGET_H
#define SELECTDATERANGEWIDGET_H

#include <QWidget>

class QHBoxLayout;

class SelectDateRangeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SelectDateRangeWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QHBoxLayout *layout;
};

#endif // SELECTDATERANGEWIDGET_H
