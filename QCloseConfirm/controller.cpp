#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
}

bool Controller::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Close)
    {
        emit closing();
        return !canClose();
    }

    return QObject::eventFilter(obj, event);
}
