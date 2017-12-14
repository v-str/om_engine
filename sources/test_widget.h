#ifndef TEST_WIDGET_H
#define TEST_WIDGET_H

#include <QFrame>
#include <QLabel>
#include <QWidget>

#include <om_button.h>
#include <widget_animator.h>

using namespace om_widgets;
using namespace om_animation;

class TestWidget : public QWidget {
  Q_OBJECT
 public:
  explicit TestWidget(QWidget* parent = nullptr);
  ~TestWidget();

 private:
  void SetAppearance();
  void SetWidgets();
  void SetAnimation();
  void SetConnections();

  QFrame* test_frame_ = nullptr;
  QLabel* test_label_ = nullptr;
  OmButton* button_open_ = nullptr;
  OmButton* button_close_ = nullptr;

  WidgetAnimator* close_animator_ = nullptr;
  WidgetAnimator* open_animator_ = nullptr;
};

#endif  // TEST_WIDGET_H
