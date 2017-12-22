#ifndef TEST_COLORIZER_H
#define TEST_COLORIZER_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QRect>

class TestColorizer {
 public:
  static void ColorizeButtons(QPushButton* button,
                              const QRect& current_geometry);
  static void ColorizeFrame(QFrame* frame, const QRect& current_geometry);
  static void ColorizeLabel(QLabel* label, const QRect& geometry);
};

#endif  // TEST_COLORIZER_H
