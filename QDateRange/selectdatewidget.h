#ifndef SELECTDATEWIDGET_H
#define SELECTDATEWIDGET_H

#include <QWidget>

class QGridLayout;

class SelectDateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SelectDateWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    virtual void closeEvent(QCloseEvent *);
    virtual void showEvent(QShowEvent *);

private:
    QGridLayout *layout;
};

#endif // SELECTDATEWIDGET_H
