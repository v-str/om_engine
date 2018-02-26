#include <work_button_frame.h>

#include <QEasingCurve>
#include <QPair>

#include <main_frame_geometries.h>
#include <v_linear_animation_group.h>
#include <widget_customizer.h>

using namespace client_code;

WorkButtonFrame::WorkButtonFrame(QFrame *parent)
    : QFrame(parent),
      frame_scaler_(new Scaler(AxesRatio(0.75, 0.0), AxesRatio(0.25, 1.0),
                               scaling::kRight,
                               scaling::kRight | scaling::kDown)),
      button_scaler_(new Scaler(AxesRatio(0.0, 0.0), AxesRatio(0.25, 0.0),
                                scaling::kRight | scaling::kDown,
                                scaling::kRight | scaling::kDown)),
      animator_(new StateAnimator(this, false)),
      work_guide_button_(new ClickButton("Work", this)),
      status_button_(new ClickButton("Status", this)),
      equipment_button_(new ClickButton("Equipment", this)),
      stuff_button_(new ClickButton("Stuff", this)),
      linear_group_(new VLinearAnimationGroup(
          this, false, VLinearAnimationGroup::kFromUpToDown, 5)) {
  SetVector();
  AddToLinearGroup();
  CustomizeFrame();
  CustomizeButtons();
  SetAnimation();
  SetConnections();
}

WorkButtonFrame::~WorkButtonFrame() {
  delete frame_scaler_;
  delete button_scaler_;
}

void WorkButtonFrame::ScaleWorkFrame(const DeltaSize &delta_size) {
  ScaleFrame(delta_size);
  ScaleButtons(delta_size);
}

ClickButton *WorkButtonFrame::GetStatusButton() { return status_button_; }

ClickButton *WorkButtonFrame::GetEquipmentButton() { return equipment_button_; }

ClickButton *WorkButtonFrame::GetStuffButton() { return stuff_button_; }

void WorkButtonFrame::Open() { animator_->Open(); }

void WorkButtonFrame::Close() { animator_->Close(); }

void WorkButtonFrame::EmitStatusButtonClick() { emit StatusButtonClicked(); }

void WorkButtonFrame::CustomizeFrame() {
  setStyleSheet(
      "QFrame{"
      "background: rgba(0, 0, 0, 60%);"
      "color: #00CC00;"
      "border: 1px solid #00CC00;"
      "border-radius: 5px;"
      "}");
  setWindowOpacity(0.5);
  setGeometry(GetWorkFrameRect());
}

void WorkButtonFrame::CustomizeButtons() {
  WidgetCustomizer::CustomizeButton(work_guide_button_,
                                    GetWorkGuideButtonRect());
  work_guide_button_->SetOffsetParameters(OffsetDistance(0, 0),
                                          widgets_utility::kDown);

  for (auto &button : button_vector_) {
    WidgetCustomizer::CustomizeButton(button.first, button.second);
    button.first->SetOffsetParameters(OffsetDistance(0, 0),
                                      widgets_utility::kDown);
  }
}

void WorkButtonFrame::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, om_animation::kDown,
                          om_animation::kUp);
  animator_->SetCurrentGeometry(geometry());
}

void WorkButtonFrame::ScaleFrame(const DeltaSize &delta_size) {
  frame_scaler_->SetDeltaSize(delta_size);
  frame_scaler_->ComputeModification(GetWorkFrameRect());

  if (!animator_->IsWidgetOpen()) {
    close();
  }

  setGeometry(frame_scaler_->GetModifiedRect());
  animator_->SetCurrentGeometry(geometry());
}

void WorkButtonFrame::ScaleButtons(const DeltaSize &delta_size) {
  button_scaler_->SetScalingFactor(AxesRatio(0.0, 0.0), AxesRatio(0.25, 0.0));
  button_scaler_->SetDeltaSize(delta_size);

  button_scaler_->ComputeModification(GetWorkGuideButtonRect());
  work_guide_button_->setGeometry(button_scaler_->GetModifiedRect());

  float y_shift = 0.0;
  float y_stretch = 0.333;

  for (auto &button : button_vector_) {
    button_scaler_->SetScalingFactor(AxesRatio(0.0, y_shift),
                                     AxesRatio(0.25, y_stretch));
    button_scaler_->ComputeModification(button.second);
    button.first->setGeometry(button_scaler_->GetModifiedRect());
    y_shift += 0.333;
  }
}

void WorkButtonFrame::SetInternalConnections() {
  connect(status_button_, SIGNAL(clicked(bool)), SLOT(EmitStatusButtonClick()));
}

void WorkButtonFrame::SetVector() {
  button_vector_.push_back(
      QPair<ClickButton *, QRect>(status_button_, GetStatusButtonRect()));
  button_vector_.push_back(
      QPair<ClickButton *, QRect>(equipment_button_, GetEquipmentButtonRect()));
  button_vector_.push_back(
      QPair<ClickButton *, QRect>(stuff_button_, GetStuffButtonRect()));
}

void WorkButtonFrame::AddToLinearGroup() {
  linear_group_->Add(status_button_);
  linear_group_->Add(equipment_button_);
  linear_group_->Add(stuff_button_);
}

void WorkButtonFrame::SetConnections() {
  connect(work_guide_button_, SIGNAL(clicked(bool)), linear_group_,
          SLOT(PerformAnimation()));
}
