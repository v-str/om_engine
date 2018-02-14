#include <button_frame.h>

#include <h_sliding_widget_set.h>

using namespace client_code;

ButtonFrame::ButtonFrame(QFrame *parent)
    : QFrame(parent),
      guide_button_(new ClickButton(this)),
      open_button_(new ClickButton("Open", this)),
      close_button_(new ClickButton("Close", this)),
      about_button_(new ClickButton("About", this)),
      clear_button_(new ClickButton("Clear", this)),
      widget_set_(new HSlidingWidgetSet(
          this, HSlidingWidgetSet::kFromLeftToRight, 5, true)) {
  widget_set_->Add(open_button_);
  widget_set_->Add(close_button_);
  //  widget_set_->Add(about_button_);
  //  widget_set_->Add(clear_button_);
  widget_set_->SetAnimationDuration(1000);

  if (widget_set_->IsSetOpen()) {
    guide_button_->setText("<-");
  } else {
    guide_button_->setText("->");
  }

  connect(guide_button_, SIGNAL(clicked(bool)), widget_set_,
          SLOT(PerformAnimation()));

  connect(guide_button_, SIGNAL(clicked(bool)), SLOT(ChangeGuideButtonText()));
}

ButtonFrame::~ButtonFrame() {}

ClickButton *ButtonFrame::OpenButton() { return open_button_; }

ClickButton *ButtonFrame::CloseButton() { return close_button_; }

ClickButton *ButtonFrame::AboutButton() { return about_button_; }

ClickButton *ButtonFrame::ClearButton() { return clear_button_; }

ClickButton *ButtonFrame::GuideButton() { return guide_button_; }

void ButtonFrame::ChangeGuideButtonText() {
  guide_button_->text() == "<-" ? guide_button_->setText("->")
                                : guide_button_->setText("<-");
}
