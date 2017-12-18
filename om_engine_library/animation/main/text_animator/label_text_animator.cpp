#include <label_text_animator.h>

LabelTextAnimator::LabelTextAnimator(QObject* parent) : QObject(parent) {}

LabelTextAnimator::LabelTextAnimator(const QString& text,
                                     bool is_running,
                                     QObject* parent)
    : QObject(parent) {
  animation_text_buffer_ = text;
  is_running_ = is_running;
}

LabelTextAnimator::~LabelTextAnimator() {}

void LabelTextAnimator::SetAnimationText(const QString& text) {
  animation_text_buffer_ = text;
}
