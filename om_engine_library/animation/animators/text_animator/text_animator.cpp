#include <text_animator.h>

#include <QMetaObject>

#include <QDebug>

TextAnimator::TextAnimator(QObject* parent, unsigned int animation_delay)
    : QObject(parent),
      animation_delay_(animation_delay),
      timer_(new QTimer(parent)) {
  connect(timer_, SIGNAL(timeout()), SLOT(AnimateText()));

  qDebug() << this->metaObject()->className();
}

TextAnimator::~TextAnimator() {}

void TextAnimator::RunTextAnimation(QLabel* animation_widget) {
  animation_widget_ = animation_widget;
  timer_->start(animation_delay_);
}

void TextAnimator::SetAnimationDelay(unsigned int animation_delay) {
  animation_delay_ = animation_delay;
}

void TextAnimator::SetAnimationText(const QString& animation_text) {
  animation_text_ = animation_text;
}

void TextAnimator::AnimateText() {
  current_text_ += animation_text_[symbol_count_];
  animation_widget_->setText(current_text_);
  ++symbol_count_;
  if (IsStringEnd()) {
    Reset();
  }
}

void TextAnimator::Reset() {
  timer_->stop();
  current_text_.clear();
  symbol_count_ = 0;
}

bool TextAnimator::IsStringEnd() const {
  return symbol_count_ == animation_text_.size();
}
