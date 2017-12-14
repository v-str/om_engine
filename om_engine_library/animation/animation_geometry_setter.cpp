#include <animation_geometry_setter.h>

#include <geometry_pair_configurator.h>

using namespace om_animation;
using namespace om_utility;

QPair<QRect, QRect> AnimationGeometrySetter::geometry_pair_;

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryFor(
    WidgetAnimationType animation_type,
    unsigned int animation_direction,
    const QRect& widget_geometry) {
  return GeometryPairConfigurator::GetGeometryFor(
      animation_type, animation_direction, widget_geometry);

  // if (animation_type == kOpen) {
  // return OpenConfigurationGeometry::GetGeometryCongiguration
  //                                (animation_direction, widget_geometry);

  // if (animation_type == kClose){
  // return CloseConfigurationGeometry::GetGeometryConfiguration
  //                                (animation_direction, widget_geometry);
}
