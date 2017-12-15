#ifndef TEST_FRAME_H
#define TEST_FRAME_H

#include <QFrame>
#include <QLabel>

#include <om_button.h>
#include <widget_animator.h>

using namespace om_widgets;
using namespace om_animation;

class TestFrame : public QFrame {
  Q_OBJECT
 public:
  explicit TestFrame(QWidget* parent = nullptr);
  ~TestFrame();

 private:
  void SetTestFrame();
  void SetWidgets();
  void SetLabel();
  void SetAnimation();
  void SetConnections();

  OmButton* open_button_ = nullptr;
  OmButton* close_button_ = nullptr;

  QLabel* test_label_ = nullptr;

  WidgetAnimator* animator_ = nullptr;
};

#endif  // TEST_FRAME_H
