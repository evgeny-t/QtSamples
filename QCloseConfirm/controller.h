#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQuickWindow>


class Controller : public QObject
{
    Q_OBJECT

    bool m_canClose;

public:
    explicit Controller(QObject *parent = 0);

    Q_PROPERTY(bool canClose READ canClose WRITE setcanClose NOTIFY canCloseChanged)

    bool canClose() const
    {
        return m_canClose;
    }

signals:
    void closing();

    void canCloseChanged(bool arg);

public slots:
    void setcanClose(bool arg)
    {
        if (m_canClose != arg) {
            m_canClose = arg;
            emit canCloseChanged(arg);
        }
    }

protected:
    bool eventFilter(QObject *, QEvent *);
};

#endif // CONTROLLER_H
