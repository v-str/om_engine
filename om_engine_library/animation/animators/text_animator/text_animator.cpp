#include <text_animator.h>

using namespace om_animation;

TextAnimator::TextAnimator(QObject* parent, unsigned int animation_delay_msec)
    : QObject(parent),
      animation_delay_msec_(animation_delay_msec),
      timer_(new QTimer(parent)) {
  connect(timer_, SIGNAL(timeout()), SLOT(AnimateText()));
}

TextAnimator::~TextAnimator() {}

void TextAnimator::SetAnimationDelay(unsigned int animation_delay_msec) {
  animation_delay_msec_ = animation_delay_msec;
}

void TextAnimator::SetAnimationText(const QString& animation_text) {
  animation_text_ = animation_text;
}

void TextAnimator::ResetAnimation() {
  timer_->stop();
  current_text_.clear();
  symbol_count_ = 0;
}

void TextAnimator::AnimateText() {
  current_text_ += animation_text_[symbol_count_];
  writable_widget_->SetText(current_text_);
  ++symbol_count_;
  if (IsStringEnd()) {
    emit TextAnimationComplete();
    ResetAnimation();
  }
}

bool TextAnimator::IsStringEnd() const {
  return symbol_count_ == animation_text_.size();
}
