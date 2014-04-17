#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "selectdaterangewidget.h"

class QVBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QVBoxLayout *layout;
};

#endif // MAINWINDOW_H
