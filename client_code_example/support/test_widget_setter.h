#ifndef TEST_WIDGET_SETTER_H
#define TEST_WIDGET_SETTER_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QRect>

#include <click_button.h>

namespace demo_code {

using namespace om_widgets;

class TestWidgetSetter {
 public:
  static void CustomizeButton(ClickButton* button,
                              const QRect& current_geometry);
  static void CustomizeFrame(QFrame* frame, const QRect& current_geometry);
  static void CustomizeLabel(QLabel* label, const QRect& geometry);
  static void CustomizeTestLabel(QLabel* test_label,
                                 const QRect initial_geometry);
};
}

#endif  // TEST_WIDGET_SETTER_H
