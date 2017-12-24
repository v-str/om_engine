#ifndef SINGLE_TEST_WIDGET_H
#define SINGLE_TEST_WIDGET_H

#include <QFrame>
#include <QWidget>

#include <om_button.h>
#include <test_frame.h>
#include <widget_animator.h>

using namespace om_widgets;
using namespace om_animation;

class MainTestWidget : public QWidget {
  Q_OBJECT
 public:
  explicit MainTestWidget(QWidget* parent = nullptr);
  ~MainTestWidget();

 private slots:
  void MultipleClickCathed();

 private:
  void SetAppearance();
  void SetWidgets();
  void SetAnimation();
  void SetConnections();

  TestFrame* test_frame_ = nullptr;
  OmButton* button_open_ = nullptr;
  OmButton* button_close_ = nullptr;
  WidgetAnimator* animator_ = nullptr;
};

#endif  // SINGLE_TEST_WIDGET_H
