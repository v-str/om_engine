#include <test_widget_setter.h>

#include <axes_ratio.h>
#include <offset_distance.h>
#include <widgets_utility.h>

using namespace demo_code;
using namespace om_widgets;
using namespace widgets_utility;

void TestWidgetSetter::CustomizeButton(ClickButton* button,
                                       const QRect& current_geometry) {
  button->setStyleSheet(
      "QPushButton{"
      "background-color: rgba(0, 0, 0, 70%);"
      "color: #00CC00;"
      "border: 2px solid #00CC00;"
      "border-radius: 5px;"
      "}"
      "QPushButton:hover:pressed { "
      "border: 2px solid red;"
      "color: red; }");
  button->setWindowOpacity(0.5);
  button->setGeometry(current_geometry);
  button->SetOffsetParameters(OffsetDistance(2, 2), Side::kRight | Side::kDown);
}

void TestWidgetSetter::CustomizeFrame(QFrame* frame,
                                      const QRect& current_geometry) {
  frame->setStyleSheet(
      "QFrame{"
      "background: rgba(0, 0, 0, 60%);"
      "color: #00CC00;"
      "border: 2px solid #00CC00;"
      "border-radius: 5px;"
      "}");
  frame->setWindowOpacity(0.5);
  frame->setGeometry(current_geometry);
}

void TestWidgetSetter::CustomizeLabel(QLabel* label, const QRect& geometry) {
  label->setStyleSheet(
      "QLabel{"
      "background-color: rgba(0, 0, 0, 60%);"
      "border: 2px solid #00CC00;"
      "border-radius: 5px;"
      "color: #00CC00;"
      "}");
  label->setGeometry(geometry);
  label->setAlignment(Qt::AlignCenter);
  label->setWordWrap(true);
}
