#ifndef WRITABLE_MATCHER_H
#define WRITABLE_MATCHER_H

#include <QString>
#include <QVector>

namespace om_animation {
class WritableMatcher {
 public:
  static QVector<QString> WritableWidgets();
  static void SetWritableWidgets(const QVector<QString>& writable_widgets);
  static bool IsWidgetWritable(const QString& widget_name);

 private:
  static QVector<QString> writable_widgets_;
};
}

#endif  // WRITABLE_MATCHER_H
