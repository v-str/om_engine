#include <animation_geometry_setter.h>

#include <om_utility.h>

using namespace om_animation;
using namespace om_utility;

QPair<QRect, QRect> AnimationGeometrySetter::geometry_pair_;

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryFor(
    AnimationGeometrySetter::AnimationType animation_type,
    unsigned int animation_direction,
    const QRect& widget_geometry) {
  // return GeometryPairConfigurator(animation_type,
  //  animation_direction, widget_geometry);
}

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryForClosing(
    unsigned int animation_direction, const QRect& widget_geometry) {
  SetAnimationGeometryForClosing(animation_direction, widget_geometry);
  return geometry_pair_;
}

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryForOpening(
    unsigned int animation_direction, const QRect& widget_geometry) {
  SetAnimationGeometryForOpening(animation_direction, widget_geometry);
  return geometry_pair_;
}

void AnimationGeometrySetter::SetAnimationGeometryForClosing(
    unsigned int animation_direction, const QRect& widget_geometry) {
  geometry_pair_.first = widget_geometry;

  int x = widget_geometry.x();
  int y = widget_geometry.y();
  int width = widget_geometry.width();
  int height = widget_geometry.height();

  if (animation_direction & Side::kUp) {
    height = 0;
  }
  if (animation_direction & Side::kDown) {
    y += height;
    height = 0;
  }
  if (animation_direction & Side::kLeft) {
    width = 0;
  }
  if (animation_direction & Side::kRight) {
    x += width;
    width = 0;
  }

  geometry_pair_.second = QRect(x, y, width, height);
}

void AnimationGeometrySetter::SetAnimationGeometryForOpening(
    unsigned int animation_direction, const QRect& widget_geometry) {
  geometry_pair_.second = widget_geometry;

  int x = widget_geometry.x();
  int y = widget_geometry.y();
  int width = widget_geometry.width();
  int height = widget_geometry.height();

  if (animation_direction & Side::kUp) {
    y += height;
    height = 0;
  }
  if (animation_direction & Side::kDown) {
    height = 0;
  }
  if (animation_direction & Side::kLeft) {
    x += width;
    width = 0;
  }
  if (animation_direction & Side::kRight) {
    width = 0;
  }

  geometry_pair_.first = (QRect(x, y, width, height));
}
