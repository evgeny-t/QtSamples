#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QtQml>

#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Controller controller; //
    QtQuick2ApplicationViewer viewer;


    viewer.rootContext()->
            setContextProperty("controller", &controller); //
    viewer.installEventFilter(&controller);

    viewer.setMainQmlFile(QStringLiteral("qml/QCloseConfirm/main.qml"));

//    QObject::connect(
//                &viewer,
//                SIGNAL(closing(QQuickCloseEvent*)),
//                &controller,
//                SLOT(closing(QQuickCloseEvent*)));


    viewer.showExpanded();

    return app.exec();
}
