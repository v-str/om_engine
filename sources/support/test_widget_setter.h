#ifndef TEST_WIDGET_SETTER_H
#define TEST_WIDGET_SETTER_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QRect>

#include <om_button.h>

namespace demo_code {

using namespace om_widgets;

class TestWidgetSetter {
 public:
  static void ColorizeButton(OmButton* button,
                             const QRect& current_geometry);
  static void ColorizeFrame(QFrame* frame, const QRect& current_geometry);
  static void ColorizeLabel(QLabel* label, const QRect& geometry);
};
}

#endif  // TEST_WIDGET_SETTER_H
