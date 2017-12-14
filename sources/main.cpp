#include <QApplication>

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QWidget>

#include <test_widget.h>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  TestWidget widget;
  widget.show();

  return app.exec();
}
