#include <test_widget_setter.h>

#include <om_button.h>

void TestWidgetSetter::ColorizeButton(QPushButton* button,
                                   const QRect& current_geometry) {
  button->setStyleSheet(
      "QPushButton{"
      "background-color: rgba(0, 0, 0, 50%);"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}"
      "QPushButton:hover:pressed { "
      "border: 2px solid red;"
      "color: red; }");
  button->setWindowOpacity(0.5);
  button->setGeometry(current_geometry);
  qobject_cast<om_widgets::OmButton*>(button)->SetOffsetDistance(
      om_utility::OffsetDistance(2, 2));
  qobject_cast<om_widgets::OmButton*>(button)->SetOffsetSide(
      om_utility::Side::kRight | om_utility::Side::kDown);
}

void TestWidgetSetter::ColorizeFrame(QFrame* frame,
                                  const QRect& current_geometry) {
  frame->setStyleSheet(
      "QFrame{"
      "background: rgba(0, 0, 0, 50%);"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
  frame->setWindowOpacity(0.5);
  frame->setGeometry(current_geometry);
}

void TestWidgetSetter::ColorizeLabel(QLabel* label, const QRect& geometry) {
  label->setStyleSheet(
      "QLabel{"
      "background-color: rgba(0, 0, 0, 50%);"
      "border: 2px solid #00FFFF;"
      "color: #00FFFF;"
      "}");
  label->setGeometry(geometry);
  label->setAlignment(Qt::AlignCenter);
  label->setWordWrap(true);
}
