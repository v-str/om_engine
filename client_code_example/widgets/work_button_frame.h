#ifndef WORK_BUTTON_FRAME_H
#define WORK_BUTTON_FRAME_H

#include <QFrame>

#include <QVector>

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

  void ScaleWorkFrame(const DeltaSize& delta_size);

  ClickButton* GetStatusButton();
  ClickButton* GetEquipmentButton();
  ClickButton* GetStuffButton();

 signals:
  void StatusButtonClicked();

 public slots:
  void Open();
  void Close();

 private slots:
  void EmitStatusButtonClick();

 private:
  void CustomizeFrame();
  void CustomizeButtons();
  void SetAnimation();
  void ScaleFrame(const DeltaSize& delta_size);
  void ScaleButtons(const DeltaSize& delta_size);
  void SetInternalConnections();
  void SetVector();
  void AddToLinearGroup();
  void SetConnections();

  Scaler* frame_scaler_ = nullptr;
  Scaler* button_scaler_ = nullptr;
  StateAnimator* animator_ = nullptr;

  ClickButton* work_guide_button_ = nullptr;
  ClickButton* status_button_ = nullptr;
  ClickButton* equipment_button_ = nullptr;
  ClickButton* stuff_button_ = nullptr;

  QVector<QPair<ClickButton*, QRect>> button_vector_;
  LinearAnimationGroup* linear_group_ = nullptr;
};
}

#endif  // WORK_BUTTON_FRAME_H
