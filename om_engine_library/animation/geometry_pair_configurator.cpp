#include <geometry_pair_configurator.h>

using namespace om_animation;
using namespace om_utility;

QPair<QRect, QRect> GeometryPairConfigurator::geometry_pair_;

QPair<QRect, QRect> GeometryPairConfigurator::GetGeometryFor(
    om_utility::WidgetAnimationType type,
    unsigned int animation_direction,
    const QRect& widget_geometry) {
  int x = widget_geometry.x();
  int y = widget_geometry.y();
  int width = widget_geometry.width();
  int height = widget_geometry.height();

  if (type == WidgetAnimationType::kOpen) {
    geometry_pair_.second = widget_geometry;
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

  if (type == WidgetAnimationType::kClose) {
    geometry_pair_.first = widget_geometry;
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
  return geometry_pair_;
}
