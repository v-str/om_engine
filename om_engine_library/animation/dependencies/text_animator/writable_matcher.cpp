#include <writable_matcher.h>

using namespace om_animation;

QVector<QString> WritableMatcher::writable_widgets_ = {
    "QLabel", "QPushButton", "QLineEdit", "om_widgets::OmButton"};
bool WritableMatcher::is_conversion_acceptable_ = false;
QString WritableMatcher::current_type_;

QVector<QString> WritableMatcher::WritableWidgets() {
  return writable_widgets_;
}

void WritableMatcher::SetWritableWidgets(
    const QVector<QString>& writable_widgets) {
  writable_widgets_ = writable_widgets;
}

bool WritableMatcher::IsWidgetWritable(const QString& widget_name) {
  is_conversion_acceptable_ = writable_widgets_.contains(widget_name);
  if (is_conversion_acceptable_) {
    int index = writable_widgets_.indexOf(widget_name);
    current_type_ = writable_widgets_[index];
  }
  return is_conversion_acceptable_;
}

QString WritableMatcher::CurrentType() { return current_type_; }
