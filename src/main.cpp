#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  //engine.rootContext()->setContextProperty("Network", tem.getCommNetwrk());

  engine.load(QUrl(QStringLiteral("qrc:/MainPage.qml")));

  if (engine.rootObjects().isEmpty()) { return -1; }

  return app.exec();
}
