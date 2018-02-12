#ifndef BUTTON_FRAME_H
#define BUTTON_FRAME_H

#include <QFrame>

#include <abstract_sliding_widget_set.h>
#include <click_button.h>

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

  void Update();

 private slots:
  void ChangeGuideButtonText();

 private:
  ClickButton* guide_button_ = nullptr;
  ClickButton* open_button_ = nullptr;
  ClickButton* close_button_ = nullptr;
  ClickButton* about_button_ = nullptr;
  ClickButton* clear_button_ = nullptr;

  AbstractSlidingWidgetSet* widget_set_ = nullptr;
};
}

#endif  // BUTTON_FRAME_H
