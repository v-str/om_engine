#ifndef OM_FRAME_INHERITOR_H
#define OM_FRAME_INHERITOR_H

#include <om_frame.h>

#include <QLabel>

#include <click_button.h>
#include <state_animator.h>
#include <text_animator.h>

class QWidget;

namespace om_widgets {

using namespace om_widgets;
using namespace om_animation;

class OmFrameInheritor : public OmFrame {
  Q_OBJECT
 public:
  OmFrameInheritor(QWidget* parent = nullptr, bool is_widget_open = true);
  ~OmFrameInheritor();

 private slots:
  void DisplayText();
  void IsAnimationComplete();

 private:
  void SetFrame();
  void SetWidgets();
  void SetLabel();
  void SetLabelAnimation();
  void SetConnections();

  ClickButton* open_button_ = nullptr;
  ClickButton* close_button_ = nullptr;
  ClickButton* display_text_button_ = nullptr;
  QLabel* test_label_ = nullptr;
  StateAnimator* animator_ = nullptr;
  TextAnimator* text_animator1_ = nullptr;
};
}

#endif  // OM_FRAME_INHERITOR_H
