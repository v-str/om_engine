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
                       unsigned int slide_direction);
  virtual ~AnimationValueSetter();

  virtual void SetStartValue() = 0;
  virtual void SetEndValue() = 0;

  unsigned int slide_direction_ = 0;
  AnimationSet* animation_set_ = nullptr;
};
}

#endif  // ANIMATION_VALUE_SETTER_H
