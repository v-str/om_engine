#ifndef H_ANIMATION_VALUE_SETTER_H
#define H_ANIMATION_VALUE_SETTER_H

#include <animation_value_setter.h>

namespace om_animation {

struct HAnimationValueSetter : public AnimationValueSetter {
  enum SlideDirection { kFromLeftToRight, kFromRightToLeft };

  HAnimationValueSetter(AnimationSet *direct_animation_set = nullptr,
                        unsigned int slide_direction = kFromLeftToRight,
                        unsigned int distance_between_widgets_px = 5);
  ~HAnimationValueSetter();

  void DetermineStartXPosition() override;

  void SetDirectStartValue() override;
  void SetDirectEndValue() override;

  void CalculateLeftToRightEndValue();
  void CalculateRightToLeftEndValue();

  void AssignNewEndAnimationValue(int index, unsigned int x_position);
};
}

#endif  // H_ANIMATION_VALUE_SETTER_H
