#ifndef OM_FRAME_INHERITOR_H
#define OM_FRAME_INHERITOR_H

#include <om_frame.h>

#include <QLabel>

#include <click_button.h>
#include <scaler.h>
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

  void ModifyGeometry(const QRect& initial_geometry,
                      const DeltaSize& delta_size) override;

 private slots:
  void DisplayText();
  void IsAnimationComplete();

 private:
  void SetFrame();
  void SetWidgets();
  void SetLabel();
  void SetLabelAnimation();
  void SetConnections();
  void ScaleTestLabel(const DeltaSize& delta_size);

  ClickButton* open_button_ = nullptr;
  ClickButton* close_button_ = nullptr;
  ClickButton* display_text_button_ = nullptr;
  QLabel* test_label_ = nullptr;
  StateAnimator* animator_ = nullptr;
  TextAnimator* text_animator1_ = nullptr;
  Scaler* scaler_ = nullptr;

  static const unsigned int text_animation_delay_msec_ = 30;
};
}

#endif  // OM_FRAME_INHERITOR_H
