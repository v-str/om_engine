#include <open_configuration_geometry.h>

#include <om_utility.h>

using namespace om_animation;
using namespace om_utility;

QPair<QRect, QRect> OpenConfigurationGeometry::GetGeometryConfiguration(
    unsigned int animation_direction, const QRect& widget_geometry) {
  QPair<QRect, QRect> open_geometry_pair;

  open_geometry_pair.second = widget_geometry;

  if (animation_direction & Side::kUp) {
    y_ += height_;
    height_ = 0;
  }
  if (animation_direction & Side::kDown) {
    height_ = 0;
  }
  if (animation_direction & Side::kLeft) {
    x_ += width_;
    width_ = 0;
  }
  if (animation_direction & Side::kRight) {
    width_ = 0;
  }

  open_geometry_pair.first = QRect(x_, y_, width_, height_);
  return open_geometry_pair;
}
