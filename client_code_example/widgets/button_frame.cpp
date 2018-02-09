#include <button_frame.h>

using namespace client_code;

ButtonFrame::ButtonFrame(QFrame *parent)
    : QFrame(parent),
      guide_button_(new ClickButton("->", this)),
      open_button_(new ClickButton("Open", this)),
      close_button_(new ClickButton("Close", this)),
      about_button_(new ClickButton("About", this)),
      clear_button_(new ClickButton("Clear", this)) {
  sliding_widget_set_.Add(open_button_);
  sliding_widget_set_.Add(close_button_);
  sliding_widget_set_.Add(about_button_);
  sliding_widget_set_.Add(clear_button_);
  sliding_widget_set_.SetAnimationDuration(1000);

  connect(guide_button_, SIGNAL(clicked(bool)), &sliding_widget_set_,
          SLOT(Open()));
}

ButtonFrame::~ButtonFrame() {}

ClickButton *ButtonFrame::OpenButton() { return open_button_; }

ClickButton *ButtonFrame::CloseButton() { return close_button_; }

ClickButton *ButtonFrame::AboutButton() { return about_button_; }

ClickButton *ButtonFrame::ClearButton() { return clear_button_; }

ClickButton *ButtonFrame::GuideButton() { return guide_button_; }

void ButtonFrame::SetStartXPos(unsigned int start_x_pos_) {
  sliding_widget_set_.SetStartXPos(start_x_pos_);
}
