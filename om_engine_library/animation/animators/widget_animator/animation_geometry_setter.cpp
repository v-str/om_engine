#include <animation_geometry_setter.h>

#include <close_configuration_geometry.h>
#include <open_configuration_geometry.h>

using namespace om_animation;

Geometry AnimationGeometrySetter::kOpenGeometry =
    std::move(Geometry(new OpenConfigurationGeometry));

Geometry AnimationGeometrySetter::kCloseGeometry =
    std::move(Geometry(new CloseConfigurationGeometry));

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryFor(
    const QRect& widget_geometry, WidgetAnimationType animation_type,
    unsigned int animation_direction) {
  if (animation_type == kOpen) {
    return kOpenGeometry->GetGeometryConfiguration(animation_direction,
                                                   widget_geometry);
  }
  if (animation_type == kClose) {
    return kCloseGeometry->GetGeometryConfiguration(animation_direction,
                                                    widget_geometry);
  }
}
