#ifndef EQUIPMENT_BUTTON_FRAME_H
#define EQUIPMENT_BUTTON_FRAME_H

#include <QFrame>

namespace client_code {

class EquipmentButtonFrame : public QFrame {
  Q_OBJECT
 public:
  EquipmentButtonFrame(QFrame* parent = nullptr);
  ~EquipmentButtonFrame();

 private:
};
}

#endif  // EQUIPMENT_BUTTON_FRAME_H
