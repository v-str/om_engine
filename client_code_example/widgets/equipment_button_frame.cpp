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
      button_scaler_(new Scaler(AxesRatio(0.0, 0.0), AxesRatio(0.25, 0.0),
                                scaling::kRight,
                                scaling::kRight | scaling::kDown)),
      animator_(new StateAnimator(this, false)),
      equipment_guide_button_(new ClickButton("Equipment", this)),
      cat_5000_button_(new ClickButton("Cat P-5000", this)) {
  CustomizeFrame();
  CustomizeButtons();
  SetAnimation();
}

EquipmentButtonFrame::~EquipmentButtonFrame() {}

void EquipmentButtonFrame::ScaleEquipmentFrame(const DeltaSize &delta_size) {
  ScaleFrame(delta_size);
  ScaleButtons(delta_size);
}

void EquipmentButtonFrame::Open() { animator_->Open(); }

void EquipmentButtonFrame::Close() { animator_->Close(); }

void EquipmentButtonFrame::EmitCatP500Click() { emit CatP500Clicked(); }

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

void EquipmentButtonFrame::CustomizeButtons() {
  WidgetCustomizer::CustomizeButton(equipment_guide_button_,
                                    GetEquipmentGuideButton());
  WidgetCustomizer::CustomizeButton(cat_5000_button_,
                                    GetCaterpillarP5000Button());

  equipment_guide_button_->SetOffsetParameters(OffsetDistance(0, 0),
                                               widgets_utility::kDown);
  cat_5000_button_->SetOffsetParameters(OffsetDistance(0, 0),
                                        widgets_utility::kDown);
}

void EquipmentButtonFrame::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, om_animation::kDown,
                          om_animation::kUp);
  animator_->SetCurrentGeometry(geometry());
}

void EquipmentButtonFrame::ScaleFrame(const DeltaSize &delta_size) {
  frame_scaler_->SetDeltaSize(delta_size);
  frame_scaler_->ComputeModification(GetEquipmentFrame());

  if (!animator_->IsWidgetOpen()) {
    close();
  }

  setGeometry(frame_scaler_->GetModifiedRect());
  animator_->SetCurrentGeometry(geometry());
}

void EquipmentButtonFrame::ScaleButtons(const DeltaSize &delta_size) {
  button_scaler_->SetDeltaSize(delta_size);

  button_scaler_->ComputeModification(GetEquipmentGuideButton());
  equipment_guide_button_->setGeometry(button_scaler_->GetModifiedRect());

  button_scaler_->ComputeModification(GetCaterpillarP5000Button());
  cat_5000_button_->setGeometry(button_scaler_->GetModifiedRect());
}

void EquipmentButtonFrame::SetInternalConnections() {
  connect(cat_5000_button_, SIGNAL(clicked(bool)), SLOT(EmitCatP500Click()));
}
