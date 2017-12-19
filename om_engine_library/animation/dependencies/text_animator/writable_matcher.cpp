#include <writable_matcher.h>

using namespace om_animation;

QVector<QString> WritableMatcher::writable_widgets_ = {
    "QLabel", "QPushButton", "QLineEdit", "om_widgets::OmButton"};
bool WritableMatcher::is_conversion_acceptable_ = false;

QVector<QString> WritableMatcher::WritableWidgets() {
  return writable_widgets_;
}

void WritableMatcher::SetWritableWidgets(
    const QVector<QString>& writable_widgets) {
  writable_widgets_ = writable_widgets;
}

bool WritableMatcher::IsWidgetWritable(const QString& widget_name) {
  return is_conversion_acceptable_ = writable_widgets_.contains(widget_name);
}
