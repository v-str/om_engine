#ifndef ANIMATION_VALUE_SETTER_H
#define ANIMATION_VALUE_SETTER_H

#include <QPair>
#include <QPropertyAnimation>
#include <QVector>
#include <QWidget>

namespace om_animation {

struct AnimationValueSetter {
  typedef QVector<QPair<QWidget*, QPropertyAnimation*>> AnimationSet;

  AnimationValueSetter(AnimationSet* animation_set,
                       unsigned int slide_direction,
                       unsigned int distance_between_widgets_px);
  virtual ~AnimationValueSetter();

  virtual void DetermineStartXPosition() = 0;
  virtual void SetStartValue() = 0;
  virtual void SetEndValue() = 0;

  unsigned int slide_direction_ = 0;
  unsigned int start_x_pos_ = 0;
  unsigned int distance_between_widgets_px_ = 0;
  AnimationSet* animation_set_ = nullptr;
};
}

#endif  // ANIMATION_VALUE_SETTER_H
