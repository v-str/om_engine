#include <equipment_button_frame.h>

#include <QEasingCurve>

#include <main_frame_geometries.h>
#include <widget_customizer.h>

using namespace client_code;

EquipmentButtonFrame::EquipmentButtonFrame(QFrame *parent)
    : QFrame(parent),
      frame_scaler_(new Scaler(AxesRatio(0.75, 0.0), AxesRatio(0.25, 1.0),
                               scaling::kRight,
                               scaling::kRight | scaling::kDown)),
      animator_(new StateAnimator(this, false)) {
  CustomizeFrame();
  SetAnimation();
}

EquipmentButtonFrame::~EquipmentButtonFrame() {}

void EquipmentButtonFrame::ScaleEquipmentFrame(const DeltaSize &delta_size) {
  frame_scaler_->SetDeltaSize(delta_size);
  frame_scaler_->ComputeModification(GetEquipmentFrame());

  if (!animator_->IsWidgetOpen()) {
    close();
  }

  setGeometry(frame_scaler_->GetModifiedRect());
  animator_->SetCurrentGeometry(geometry());
}

void EquipmentButtonFrame::Open() { animator_->Open(); }

void EquipmentButtonFrame::Close() { animator_->Close(); }

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

void EquipmentButtonFrame::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, om_animation::kDown,
                          om_animation::kUp);
  animator_->SetCurrentGeometry(geometry());
}
