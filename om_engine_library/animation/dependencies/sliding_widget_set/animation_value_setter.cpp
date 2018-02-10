#include <animation_value_setter.h>

using namespace om_animation;

#include <QDebug>

AnimationValueSetter::AnimationValueSetter(
    AnimationSet *animation_set, unsigned int slide_direction,
    unsigned int distance_between_widgets_px)
    : animation_set_(animation_set),
      slide_direction_(slide_direction),
      distance_between_widgets_px_(distance_between_widgets_px) {
  qDebug() << "AnimationValueSetter: " << distance_between_widgets_px;
}

AnimationValueSetter::~AnimationValueSetter() {}
