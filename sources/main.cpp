#include <QApplication>

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QWidget>

#include <main_test_widget.h>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  MainTestWidget widget;
  widget.show();

  return app.exec();
}
