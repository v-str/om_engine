#ifndef WORK_BUTTON_FRAME_H
#define WORK_BUTTON_FRAME_H

#include <QFrame>

#include <click_button.h>
#include <linear_animation_group.h>
#include <scaler.h>
#include <state_animator.h>

namespace client_code {

using namespace om_widgets;
using namespace om_animation;
using namespace scaling;

class WorkButtonFrame : public QFrame {
  Q_OBJECT
 public:
  WorkButtonFrame(QFrame* parent = nullptr);
  ~WorkButtonFrame();

  void ScaleEquipmentFrame(const DeltaSize& delta_size);

 signals:
  void CatP500Clicked();

 public slots:
  void Open();
  void Close();

 private slots:
  void EmitCatP500Click();

 private:
  void CustomizeFrame();
  void CustomizeButtons();
  void SetAnimation();
  void ScaleFrame(const DeltaSize& delta_size);
  void ScaleButtons(const DeltaSize& delta_size);
  void SetInternalConnections();

  Scaler* frame_scaler_ = nullptr;
  Scaler* button_scaler_ = nullptr;
  StateAnimator* animator_ = nullptr;

  ClickButton* equipment_guide_button_ = nullptr;
  ClickButton* cat_5000_button_ = nullptr;
};
}

#endif  // WORK_BUTTON_FRAME_H
