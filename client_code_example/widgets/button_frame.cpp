#include <button_frame.h>

#include <QVector>

#include <h_linear_animation_group.h>
#include <main_frame_geometries.h>
#include <widget_customizer.h>

using namespace client_code;

ButtonFrame::ButtonFrame(QFrame *parent)
    : QFrame(parent),
      guide_button_(new ClickButton("#", this)),
      open_button_(new ClickButton("Open", this)),
      close_button_(new ClickButton("Close", this)),
      about_button_(new ClickButton("About", this)),
      clear_button_(new ClickButton("Clear", this)),
      linear_group_(new HLinearAnimationGroup(
          this, false, HLinearAnimationGroup::kFromLeftToRight, 5)),
      frame_scaler_(new Scaler(AxesRatio(0, 0), AxesRatio(1.0, 1.0),
                               scaling::kRight, scaling::kRight)),
      button_scaler_(new Scaler(AxesRatio(0, 0), AxesRatio(1.0, 1.0),
                                scaling::kRight, scaling::kRight)) {
  AddToLinearGroup();
  CustomizeButtonFrame();
  SetButtonParams();
  SetConnections();
}

ButtonFrame::~ButtonFrame() {
  delete frame_scaler_;
  delete button_scaler_;
}

ClickButton *ButtonFrame::OpenButton() { return open_button_; }

ClickButton *ButtonFrame::CloseButton() { return close_button_; }

ClickButton *ButtonFrame::AboutButton() { return about_button_; }

ClickButton *ButtonFrame::ClearButton() { return clear_button_; }

ClickButton *ButtonFrame::GuideButton() { return guide_button_; }

void ButtonFrame::ScaleButtonFrame(const DeltaSize &delta_size) {
  frame_scaler_->SetDeltaSize(delta_size);
  frame_scaler_->ComputeModification(GetButtonFrame());
  setGeometry(frame_scaler_->GetModifiedRect());

  ScaleButtons(delta_size);
}

void ButtonFrame::SetButtonParams() {
  open_button_->SetOffsetParameters(OffsetDistance(0, 0),
                                    widgets_utility::kDown);
  close_button_->SetOffsetParameters(OffsetDistance(0, 0),
                                     widgets_utility::kDown);
  about_button_->SetOffsetParameters(OffsetDistance(0, 0),
                                     widgets_utility::kDown);
  clear_button_->SetOffsetParameters(OffsetDistance(0, 0),
                                     widgets_utility::kDown);
}

void ButtonFrame::AddToLinearGroup() {
  linear_group_->Add(open_button_);
  linear_group_->Add(close_button_);
  linear_group_->Add(about_button_);
  linear_group_->Add(clear_button_);
  linear_group_->SetAnimationProperties(500, QEasingCurve::OutQuad);
}

void ButtonFrame::CustomizeButtonFrame() {
  setStyleSheet(
      "QFrame{"
      "background: rgba(0, 0, 0, 60%);"
      "color: #00CC00;"
      "border: 1px solid #00CC00;"
      "border-radius: 5px;"
      "}");
  setWindowOpacity(0.5);
  setGeometry(GetButtonFrame());
  WidgetCustomizer::CustomizeButton(guide_button_, GetGuideButton());
  WidgetCustomizer::CustomizeButton(open_button_, GetOpenButton());
  WidgetCustomizer::CustomizeButton(close_button_, GetCloseButton());
  WidgetCustomizer::CustomizeButton(about_button_, GetAboutButton());
  WidgetCustomizer::CustomizeButton(clear_button_, GetClearButton());
}

void ButtonFrame::SetConnections() {
  connect(guide_button_, SIGNAL(clicked(bool)), linear_group_,
          SLOT(PerformAnimation()));
}

void ButtonFrame::ScaleButtons(const DeltaSize &delta_size) {
  float shift_value = 0.0;
  float stretch_value = 0.25;

  QVector<ClickButton *> buttons = {open_button_, close_button_, about_button_,
                                    clear_button_};

  QVector<QRect> geometries = {GetOpenButton(), GetCloseButton(),
                               GetAboutButton(), GetClearButton()};

  for (size_t i = 0; i < buttons.size(); ++i) {
    button_scaler_->SetScalingFactor(AxesRatio(shift_value, shift_value),
                                     AxesRatio(stretch_value, shift_value));
    button_scaler_->SetDeltaSize(delta_size);
    button_scaler_->ComputeModification(geometries.at(i));
    buttons[i]->setGeometry(button_scaler_->GetModifiedRect());
    shift_value += 0.25;
  }
}
