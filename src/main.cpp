#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "AppManager.h"

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  AppManager manager;

  engine.rootContext()->setContextProperty("AppManager", &manager);

  engine.rootContext()->setContextProperty("PathListModel", manager.getPathList());

  engine.rootContext()->setContextProperty("EventTableModel", manager.getEventTable());

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  if (engine.rootObjects().isEmpty()) { return -1; }

  return app.exec();
}
