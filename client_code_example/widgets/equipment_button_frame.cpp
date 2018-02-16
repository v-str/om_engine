#include <equipment_button_frame.h>

#include <main_frame_geometries.h>
#include <widget_customizer.h>

using namespace client_code;

EquipmentButtonFrame::EquipmentButtonFrame(QFrame *parent) : QFrame(parent) {
  CustomizeFrame();
}

EquipmentButtonFrame::~EquipmentButtonFrame() {}

void EquipmentButtonFrame::CustomizeFrame() {
  setStyleSheet(
      "QFrame{"
      "background: rgba(0, 0, 0, 60%);"
      "color: #00CC00;"
      "border: 1px solid #00CC00;"
      "border-radius: 5px;"
      "}");
  setWindowOpacity(0.5);
  setGeometry(GetEquipmentFrame());
}
