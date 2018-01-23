#include <animation_geometry_setter.h>

#include <close_configuration_geometry.h>
#include <open_configuration_geometry.h>

using namespace om_animation;

std::unique_ptr<ConfigurationGeometry>
    AnimationGeometrySetter::kOpenConfigurationGeometry = std::move(
        std::unique_ptr<ConfigurationGeometry>(new OpenConfigurationGeometry));

std::unique_ptr<ConfigurationGeometry>
    AnimationGeometrySetter::kCloseConfigurationGeometry = std::move(
        std::unique_ptr<ConfigurationGeometry>(new CloseConfigurationGeometry));

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryFor(
    const QRect& widget_geometry, WidgetAnimationType animation_type,
    unsigned int animation_direction) {
  if (animation_type == kOpen) {
    return kOpenConfigurationGeometry->GetGeometryConfiguration(
        animation_direction, widget_geometry);
  }
  if (animation_type == kClose) {
    return kCloseConfigurationGeometry->GetGeometryConfiguration(
        animation_direction, widget_geometry);
  }
}
