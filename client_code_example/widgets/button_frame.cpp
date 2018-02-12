#include <button_frame.h>

#include <h_sliding_widget_set.h>

using namespace client_code;

ButtonFrame::ButtonFrame(QFrame *parent)
    : QFrame(parent),
      guide_button_(new ClickButton("->", this)),
      open_button_(new ClickButton("Open", this)),
      close_button_(new ClickButton("Close", this)),
      about_button_(new ClickButton("About", this)),
      clear_button_(new ClickButton("Clear", this)),
      widget_set_(
          new HSlidingWidgetSet(this, HSlidingWidgetSet::kFromRightToLeft)) {
  widget_set_->Add(open_button_);
  widget_set_->Add(close_button_);
  widget_set_->Add(about_button_);
  widget_set_->Add(clear_button_);
  widget_set_->SetAnimationDuration(200);

  connect(guide_button_, SIGNAL(clicked(bool)), widget_set_, SLOT(Open()));
}

ButtonFrame::~ButtonFrame() {}

ClickButton *ButtonFrame::OpenButton() { return open_button_; }

ClickButton *ButtonFrame::CloseButton() { return close_button_; }

ClickButton *ButtonFrame::AboutButton() { return about_button_; }

ClickButton *ButtonFrame::ClearButton() { return clear_button_; }

ClickButton *ButtonFrame::GuideButton() { return guide_button_; }

void ButtonFrame::Update() { widget_set_->UpdateWidgetSet(); }
