#ifndef EQUIPMENT_BUTTON_FRAME_H
#define EQUIPMENT_BUTTON_FRAME_H

#include <QFrame>

#include <click_button.h>
#include <linear_animation_group.h>
#include <scaler.h>

namespace client_code {

using namespace om_widgets;
using namespace om_animation;
using namespace scaling;

class EquipmentButtonFrame : public QFrame {
  Q_OBJECT
 public:
  EquipmentButtonFrame(QFrame* parent = nullptr);
  ~EquipmentButtonFrame();

  void ScaleEquipmentFrame(const DeltaSize& delta_size);

 private:
  void CustomizeFrame();

  Scaler* frame_scaler_ = nullptr;
};
}

#endif  // EQUIPMENT_BUTTON_FRAME_H
