﻿#ifndef ANIMATION_GEOMETRY_SETTER_H
#define ANIMATION_GEOMETRY_SETTER_H

#include <QPair>
#include <QRect>

namespace om_animation {
class AnimationGeometrySetter {
 public:
  static QPair<QRect, QRect> GetAnimationForClosing(
      unsigned int animation_direction, const QRect& widget_geometry);
  static QPair<QRect, QRect> GetAnimationForOpening(
      unsigned int animation_direction, const QRect& widget_geometry);

 private:
  static void SetAnimationGeometryForClosing(unsigned int animation_direction,
                                             const QRect& widget_geometry);
  static void SetAnimationGeometryForOpening(unsigned int animation_direction,
                                             const QRect& widget_geometry);

  static QPair<QRect, QRect> geometry_pair_;
};
}

#endif  // ANIMATION_GEOMETRY_SETTER_H
