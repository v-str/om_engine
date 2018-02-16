#include <button_frame.h>

#include <h_linear_animation_group.h>
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
          this, false, HLinearAnimationGroup::kFromRightToLeft, 5)) {
  WidgetCustomizer::CustomizeButtonFrame(this);

  SetButtonParams();
  AddToLinearGroup();

  connect(guide_button_, SIGNAL(clicked(bool)), linear_group_,
          SLOT(PerformAnimation()));
}

ButtonFrame::~ButtonFrame() {}

ClickButton *ButtonFrame::OpenButton() { return open_button_; }

ClickButton *ButtonFrame::CloseButton() { return close_button_; }

ClickButton *ButtonFrame::AboutButton() { return about_button_; }

ClickButton *ButtonFrame::ClearButton() { return clear_button_; }

ClickButton *ButtonFrame::GuideButton() { return guide_button_; }

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
  linear_group_->SetAnimationProperties(200, QEasingCurve::OutQuad);
}
