#ifndef TEST_FRAME_H
#define TEST_FRAME_H

#include <QFrame>
#include <QLabel>

#include <click_button.h>
#include <text_animator.h>
#include <widget_condition_animator.h>

namespace demo_code {

using namespace om_widgets;
using namespace om_animation;

class TestFrame : public QFrame {
  Q_OBJECT
 public:
  explicit TestFrame(QWidget* parent = nullptr);
  ~TestFrame();

 private slots:
  void DisplayText();
  void IsAnimationComplete();

 private:
  void SetTestFrame();
  void SetWidgets();
  void SetLabel();
  void SetAnimation();
  void SetConnections();

  ClickButton* open_button_ = nullptr;
  ClickButton* close_button_ = nullptr;
  ClickButton* display_text_button_ = nullptr;
  QLabel* test_label_ = nullptr;
  WidgetConditionAnimator* animator_ = nullptr;
  TextAnimator* text_animator1_ = nullptr;
};
}

#endif  // TEST_FRAME_H
