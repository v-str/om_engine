#include <animation_geometry_setter.h>

#include <geometry_pair_configurator.h>

using namespace om_animation;
using namespace om_utility;

QRect AnimationGeometrySetter::widget_geometry_;

QPair<QRect, QRect> AnimationGeometrySetter::GetGeometryFor(
    WidgetAnimationType animation_type,
    unsigned int animation_direction,
    const QRect& widget_geometry) {
  return GeometryPairConfigurator::GetGeometryFor(
      animation_type, animation_direction, widget_geometry);
}
