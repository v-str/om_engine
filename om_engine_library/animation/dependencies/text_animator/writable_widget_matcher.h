#ifndef WRITABLE_WIDGET_MATCHER_H
#define WRITABLE_WIDGET_MATCHER_H

#include <QString>
#include <QVector>

#include <QDebug>

class WritableWidgetMatcher {
 public:
  static QVector<QString> WritableWidgets();
  static void SetWritableWidgets(const QVector<QString>& writable_widgets);
  static bool IsWidgetWritable(const QString& widget_name);
  static QString CurrentType();

 private:
  static QVector<QString> writable_widgets_;
  static bool is_conversion_acceptable_;
  static QString current_type_;
};

#endif  // WRITABLE_WIDGET_MATCHER_H
