#include <test_widget_setter.h>

#include <modification_factor.h>
#include <om_utility.h>

using namespace demo_code;
using namespace om_utility;

void TestWidgetSetter::CustomizeButton(OmButton* button,
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
  button->SetOffsetDistance(OffsetDistance(2, 2));
  button->SetOffsetSide(Side::kRight | Side::kDown);

  button->SetGeometryComposer(ModificationFactor(0.3, 0.0), kRight,
                              kStretching);
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
      "border-radius: 5px;"
      "color: #00FFFF;"
      "}");
  label->setGeometry(geometry);
  label->setAlignment(Qt::AlignCenter);
  label->setWordWrap(true);
}
