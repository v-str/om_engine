﻿#ifndef WIDGET_CUSTOMIZER_H
#define WIDGET_CUSTOMIZER_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QRect>
#include <QString>

#include <button_frame.h>
#include <click_button.h>

namespace client_code {

using namespace om_widgets;

class WidgetCustomizer {
 public:
  static void CustomizeButton(ClickButton* button,
                              const QRect& current_geometry);
  static void CustomizeFrame(QFrame* frame, const QRect& current_geometry);
  static void CustomizeLabel(QLabel* label, const QRect& geometry);
  static void CustomizeTestLabel(QLabel* test_label,
                                 const QRect initial_geometry);

  static QString GetAnimationText();
};
}

#endif  // WIDGET_CUSTOMIZER_H
