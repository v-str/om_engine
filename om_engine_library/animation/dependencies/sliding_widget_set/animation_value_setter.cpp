#include <animation_value_setter.h>

using namespace om_animation;

AnimationValueSetter::AnimationValueSetter(
    AnimationSet *direct_animation_set, AnimationSet *reverse_animation_set,
    unsigned int slide_direction, unsigned int distance_between_widgets_px)
    : direct_animation_set_(direct_animation_set),
      reverse_animation_set_(reverse_animation_set),
      slide_direction_(slide_direction),
      distance_between_widgets_px_(distance_between_widgets_px) {}

AnimationValueSetter::~AnimationValueSetter() {}
