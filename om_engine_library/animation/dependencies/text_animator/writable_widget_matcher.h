#ifndef WRITABLE_WIDGET_MATCHER_H
#define WRITABLE_WIDGET_MATCHER_H

#include <QString>
#include <QVector>

#include <QDebug>

class WritableWidgetMatcher {
 public:
  static QVector<QString> WritableWidgets();
  static void SetWritableWidgets(const QVector<QString>& WritableWidgets);
  static bool IsWidgetWrirable(const QString& widget_name);

 private:
  static QVector<QString> writable_widgets_;
  static bool is_conversion_acceptable_;
};

#endif  // WRITABLE_WIDGET_MATCHER_H

QVector<QString> WritableWidgetMatcher::writable_widgets_ = {
    "QLabel", "QPushButton", "QLineEdit"};

bool WritableWidgetMatcher::is_conversion_acceptable_ = false;

QVector<QString> WritableWidgetMatcher::WritableWidgets() {
  return writable_widgets_;
}

void WritableWidgetMatcher::SetWritableWidgets(
    const QVector<QString>& writable_widgets) {
  writable_widgets_ = writable_widgets;
}

bool WritableWidgetMatcher::IsWidgetWrirable(const QString& widget_name) {
  return is_conversion_acceptable_ == writable_widgets_.contains(widget_name);
}
