﻿#ifndef TITLE_BUTTON_FRAME_H
#define TITLE_BUTTON_FRAME_H

#include <QFrame>

#include <click_button.h>
#include <linear_animation_group.h>
#include <scaler.h>

namespace client_code {

using namespace om_widgets;
using namespace om_animation;
using namespace scaling;

class TitleButtonFrame : public QFrame {
  Q_OBJECT
 public:
  TitleButtonFrame(QFrame* parent = nullptr);
  ~TitleButtonFrame();

  ClickButton* OpenButton();
  ClickButton* CloseButton();
  ClickButton* AboutButton();
  ClickButton* ClearButton();
  ClickButton* GuideButton();

  void ScaleButtonFrame(const DeltaSize& delta_size);

 private:
  void SetButtonParams();
  void AddToLinearGroup();
  void CustomizeButtonFrame();
  void SetConnections();
  void ScaleButtons(const DeltaSize& delta_size);

  ClickButton* guide_button_ = nullptr;
  ClickButton* open_button_ = nullptr;
  ClickButton* close_button_ = nullptr;
  ClickButton* about_button_ = nullptr;
  ClickButton* clear_button_ = nullptr;

  LinearAnimationGroup* linear_group_ = nullptr;
  Scaler* frame_scaler_ = nullptr;
  Scaler* button_scaler_ = nullptr;
};
}

#endif  // TITLE_BUTTON_FRAME_H