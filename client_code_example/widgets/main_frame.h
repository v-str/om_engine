#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <om_frame.h>

#include <QLabel>

#include <font_size_generator.h>
#include <scaler.h>
#include <state_animator.h>
#include <text_animator.h>
#include <title_button_frame.h>

class QWidget;

namespace client_code {

using namespace om_widgets;
using namespace om_animation;

class MainFrame : public OmFrame {
  Q_OBJECT
 public:
  MainFrame(QWidget* parent = nullptr, bool is_widget_open = true);
  ~MainFrame();

  void ModifyGeometry(const QRect& initial_geometry,
                      const DeltaSize& delta_size) override;

 private slots:
  void DisplayText();
  void ClearTestLabel();

 private:
  void SetWidgets();
  void SetLabelAnimation();
  void SetConnections();
  void ScaleTestLabel(const DeltaSize& delta_size);

  TitleButtonFrame* button_frame_ = nullptr;
  QLabel* main_label_ = nullptr;
  StateAnimator* animator_ = nullptr;
  TextAnimator* text_animator1_ = nullptr;
  Scaler* scaler_ = nullptr;
  FontSizeGenerator* font_size_generator_ = nullptr;

  static const unsigned int text_animation_delay_msec_ = 10;
};
}

#endif  // MAIN_FRAME_H
