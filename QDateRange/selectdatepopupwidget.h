#ifndef SELECTDATEPOPUPWIDGET_H
#define SELECTDATEPOPUPWIDGET_H

#include <QWidget>
#include <QDate>

class QGridLayout;

class SelectDatePopupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SelectDatePopupWidget(QWidget *parent = 0);

    QDate selectedDate() const;
signals:
    void onOk(QDate);
public slots:

protected:
    virtual void closeEvent(QCloseEvent *);
    virtual void showEvent(QShowEvent *);

private:
    QGridLayout *layout;
};

#endif // SELECTDATEPOPUPWIDGET_H
