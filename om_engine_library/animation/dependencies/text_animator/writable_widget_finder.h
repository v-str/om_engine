#ifndef WRITABLE_WIDGET_FINDER_H
#define WRITABLE_WIDGET_FINDER_H

#include <QString>
#include <QVector>

#include <QDebug>

class WritableWidgetFinder {
 public:
  static QVector<QString> WritableWidgets();
  static void SetWritableWidgets(const QVector<QString>& WritableWidgets);
  static bool IsWidgetWrirable(const QString& widget_name);

 private:
  static QVector<QString> writable_widgets_;
  static bool is_conversion_acceptable_;
};

#endif  // WRITABLE_WIDGET_FINDER_H

QVector<QString> WritableWidgetFinder::writable_widgets_ = {
    "QLabel", "QPushButton", "QLineEdit"};

bool WritableWidgetFinder::is_conversion_acceptable_ = false;

QVector<QString> WritableWidgetFinder::WritableWidgets() {
  return writable_widgets_;
}

void WritableWidgetFinder::SetWritableWidgets(
    const QVector<QString>& writable_widgets) {
  writable_widgets_ = writable_widgets;
}

bool WritableWidgetFinder::IsWidgetWrirable(const QString& widget_name) {
  return is_conversion_acceptable_ = writable_widgets_.contains(widget_name);
}
