#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QHBoxLayout;
class QPushButton;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QHBoxLayout *layout;
    QPushButton *button;
    QTextEdit *textedit;
};

#endif // MAINWINDOW_H
