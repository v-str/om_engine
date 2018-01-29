#include <QApplication>

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QWidget>

#include <main_test_widget.h>

using namespace demo_code;

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  Q_INIT_RESOURCE(om_engine_resources);

  MainTestWidget widget;
  widget.show();

  return app.exec();
}
