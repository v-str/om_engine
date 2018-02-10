#include <h_animation_value_setter.h>

using namespace om_animation;

HAnimationValueSetter::HAnimationValueSetter(
    AnimationValueSetter::AnimationSet *animation_set,
    unsigned int slide_direction)
    : AnimationValueSetter(animation_set, slide_direction) {}

HAnimationValueSetter::~HAnimationValueSetter() {}

void HAnimationValueSetter::DetermineStartXPosition() {
  if (!animation_set_->isEmpty()) {
    if (slide_direction_ == kFromLeftToRight) {
      unsigned int x_of_first_widget = animation_set_->first().first->x();
      start_x_pos_ = x_of_first_widget;
    }
    // if (slide_direction_ == kFromRightToLeft) {}
  }
}

void HAnimationValueSetter::SetStartValue() {}

void HAnimationValueSetter::SetEndValue() {}
