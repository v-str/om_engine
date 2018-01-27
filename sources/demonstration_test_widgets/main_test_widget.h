﻿#ifndef MAIN_TEST_WIDGET_H
#define MAIN_TEST_WIDGET_H

#include <QFrame>
#include <QWidget>

#include <abstract_clock.h>
#include <click_button.h>
#include <state_animator.h>
#include <delta_size.h>
#include <test_frame.h>

namespace demo_code {

using namespace om_widgets;
using namespace om_animation;
using namespace geometry_modification;

class MainTestWidget : public QWidget {
  Q_OBJECT
 public:
  explicit MainTestWidget(QWidget* parent = nullptr);
  ~MainTestWidget();

 protected:
  void resizeEvent(QResizeEvent*);

 signals:
  void TestFrameGeometryChanged(const QRect&);

 private slots:
  void MultipleClickCathed();
  void ResetAnimationForTestGeometry(const QRect& current_geometry);

 private:
  void SetAppearance();
  void SetWidgets();
  void SetAnimation();
  void SetConnections();
  DeltaSize GetDeltaSize();

  TestFrame* test_frame_ = nullptr;
  ClickButton* button_open_ = nullptr;
  ClickButton* button_close_ = nullptr;
  StateAnimator* animator_ = nullptr;
  AbstractClock* time_label_ = nullptr;
  AbstractClock* date_label_ = nullptr;

  DeltaSize delta_size_;
};
}

#endif  // MAIN_TEST_WIDGET_H
