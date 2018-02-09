#ifndef ANIMATION_VALUE_SETTER_H
#define ANIMATION_VALUE_SETTER_H

#include <QPair>
#include <QPropertyAnimation>
#include <QVector>
#include <QWidget>

namespace om_animation {

class AnimationValueSetter {
 public:
  typedef QVector<QPair<QWidget*, QPropertyAnimation*>> AnimationSet;

  virtual void SetStartValue(AnimationSet* animation_set) = 0;
  virtual void SetEndValue(AnimationSet* animation_set) = 0;
};
}

#endif  // ANIMATION_VALUE_SETTER_H
