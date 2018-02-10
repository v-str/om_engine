#include <animation_value_setter.h>

using namespace om_animation;

AnimationValueSetter::AnimationValueSetter(AnimationSet *animation_set,
                                           unsigned int slide_direction)
    : animation_set_(animation_set), slide_direction_(slide_direction) {}

AnimationValueSetter::~AnimationValueSetter() {}
