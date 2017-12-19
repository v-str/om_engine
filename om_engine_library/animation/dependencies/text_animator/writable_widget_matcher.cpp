#include <writable_widget_matcher.h>

QVector<QString> WritableWidgetMatcher::writable_widgets_ = {
    "QLabel", "QPushButton", "QLineEdit", "om_widgets::OmButton"};
bool WritableWidgetMatcher::is_conversion_acceptable_ = false;
QString WritableWidgetMatcher::current_type_;

QVector<QString> WritableWidgetMatcher::WritableWidgets() {
  return writable_widgets_;
}

void WritableWidgetMatcher::SetWritableWidgets(
    const QVector<QString>& writable_widgets) {
  writable_widgets_ = writable_widgets;
}

bool WritableWidgetMatcher::IsWidgetWritable(const QString& widget_name) {
  is_conversion_acceptable_ = writable_widgets_.contains(widget_name);
  if (is_conversion_acceptable_) {
    int index = writable_widgets_.indexOf(widget_name);
    current_type_ = writable_widgets_[index];
  }
  return is_conversion_acceptable_;
}

QString WritableWidgetMatcher::CurrentType() { return current_type_; }
