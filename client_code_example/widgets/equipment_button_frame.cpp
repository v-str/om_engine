#include <equipment_button_frame.h>

#include <main_frame_geometries.h>
#include <widget_customizer.h>

using namespace client_code;

EquipmentButtonFrame::EquipmentButtonFrame(QFrame *parent)
    : QFrame(parent),
      frame_scaler_(new Scaler(AxesRatio(0.75, 0.0), AxesRatio(0.25, 1.0),
                               scaling::kRight,
                               scaling::kRight | scaling::kDown)) {
  CustomizeFrame();
}

EquipmentButtonFrame::~EquipmentButtonFrame() {}

void EquipmentButtonFrame::ScaleEquipmentFrame(const DeltaSize &delta_size) {
  frame_scaler_->SetDeltaSize(delta_size);
  frame_scaler_->ComputeModification(GetEquipmentFrame());
  setGeometry(frame_scaler_->GetModifiedRect());
}

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
