#ifndef MAIN_TEST_WIDGET_H
#define MAIN_TEST_WIDGET_H

#include <QFrame>
#include <QWidget>

#include <abstract_clock.h>
#include <click_button.h>
#include <delta_size.h>
#include <geometry_modifier.h>
#include <om_frame_inheritor.h>

namespace demo_code {

using namespace om_widgets;
using namespace om_animation;
using namespace scaling;

class MainTestWidget : public QWidget {
  Q_OBJECT
 public:
  explicit MainTestWidget(QWidget* parent = nullptr);
  ~MainTestWidget();

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void SetAppearance();
  void SetWidgets();
  void SetAnimation();
  void SetConnections();
  void ShiftClocks();
  DeltaSize GetDeltaSize();

  ClickButton* button_open_ = nullptr;
  ClickButton* button_close_ = nullptr;
  AbstractClock* time_label_ = nullptr;
  AbstractClock* date_label_ = nullptr;
  OmFrameInheritor* inheritor_ = nullptr;
  GeometryModifier* shifter_ = nullptr;
};
}

#endif  // MAIN_TEST_WIDGET_H
