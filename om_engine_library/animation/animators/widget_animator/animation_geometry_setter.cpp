#include <animation_geometry_setter.h>

using namespace om_animation;
using namespace om_utility;

OpenConfigurationGeometry AnimationGeometrySetter::kOpenConfigurationGeometry;
CloseConfigurationGeometry AnimationGeometrySetter::kCloseConfigurationGeometry;

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryFor(
    const QRect& widget_geometry, WidgetAnimationType animation_type,
    unsigned int animation_direction) {
  if (animation_type == kOpen) {
    return kOpenConfigurationGeometry.GetGeometryConfiguration(
        animation_direction, widget_geometry);
  }
  if (animation_type == kClose) {
    return kCloseConfigurationGeometry.GetGeometryConfiguration(
        animation_direction, widget_geometry);
  }
}
