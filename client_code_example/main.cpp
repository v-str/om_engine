#include <QApplication>

#include <main_widget.h>

using namespace client_code;

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  Q_INIT_RESOURCE(om_engine_resources);
  MainWidget widget;
  widget.show();
  return app.exec();
}
