#include <h_animation_value_setter.h>

using namespace om_animation;

HAnimationValueSetter::HAnimationValueSetter(
    AnimationValueSetter::AnimationSet *animation_set,
    unsigned int slide_direction)
    : AnimationValueSetter(animation_set, slide_direction) {}

HAnimationValueSetter::~HAnimationValueSetter() {}

void HAnimationValueSetter::SetStartValue() {}

void HAnimationValueSetter::SetEndValue() {}
