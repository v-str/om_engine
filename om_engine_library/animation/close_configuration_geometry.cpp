#include <close_configuration_geometry.h>

#include <om_utility.h>

using namespace om_animation;
using namespace om_utility;

QPair<QRect, QRect>
om_animation::CloseConfigurationGeometry::GetGeometryConfiguration(
    unsigned int animation_direction, const QRect& widget_geometry) {
  QPair<QRect, QRect> close_geometry_pair;

  close_geometry_pair.first = widget_geometry;
  if (animation_direction & Side::kUp) {
    height_ = 0;
  }
  if (animation_direction & Side::kDown) {
    y_ += height_;
    height_ = 0;
  }
  if (animation_direction & Side::kLeft) {
    width_ = 0;
  }
  if (animation_direction & Side::kRight) {
    x_ += width_;
    width_ = 0;
  }
  close_geometry_pair.second = QRect(x_, y_, width_, height_);

  return close_geometry_pair;
}
