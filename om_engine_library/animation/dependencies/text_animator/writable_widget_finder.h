#ifndef WRITABLE_WIDGET_FINDER_H
#define WRITABLE_WIDGET_FINDER_H

#include <QString>
#include <QVector>

#include <QDebug>

class WritableWidgetFinder {
 public:
  static QVector<QString> WritableWidgets();
  static void SetWritableWidgets(const QVector<QString>& WritableWidgets);

 private:
  static QVector<QString> writable_widgets_;
};

#endif  // WRITABLE_WIDGET_FINDER_H

QVector<QString> WritableWidgetFinder::writable_widgets_ = {
    "QLabel", "QPushButton", "QLineEdit"};

QVector<QString> WritableWidgetFinder::WritableWidgets() {
  return writable_widgets_;
}

void WritableWidgetFinder::SetWritableWidgets(
    const QVector<QString>& writable_widgets) {
  writable_widgets_ = writable_widgets;
}
