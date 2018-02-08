#ifndef BUTTON_FRAME_H
#define BUTTON_FRAME_H

#include <QFrame>

#include <click_button.h>
#include <sliding_widget_set.h>

namespace client_code {

using namespace om_widgets;
using namespace om_animation;

class ButtonFrame : public QFrame {
  Q_OBJECT
 public:
  ButtonFrame(QFrame* parent = nullptr);
  ~ButtonFrame();

  ClickButton* OpenButton();
  ClickButton* CloseButton();
  ClickButton* AboutButton();
  ClickButton* ClearButton();
  ClickButton* GuideButton();

  void SetStartXPos(unsigned int start_x_pos_);

 private:
  ClickButton* guide_button_ = nullptr;
  ClickButton* open_button_ = nullptr;
  ClickButton* close_button_ = nullptr;
  ClickButton* about_button_ = nullptr;
  ClickButton* clear_button_ = nullptr;

  SlidingWidgetSet sliding_widget_set_;
};
}

#endif  // BUTTON_FRAME_H
