#ifndef ANIMATION_GEOMETRY_SETTER_H
#define ANIMATION_GEOMETRY_SETTER_H

#include <QPair>
#include <QRect>

#include <om_utility.h>

#include <close_configuration_geometry.h>
#include <open_configuration_geometry.h>

namespace om_animation {
class AnimationGeometrySetter {
 public:
  static QPair<QRect, QRect> GetGeometryFor(
      om_utility::WidgetAnimationType animation_type,
      unsigned int animation_direction,
      const QRect& widget_geometry);

 private:
  static OpenConfigurationGeometry kOpenConfigurationGeometry;
  static CloseConfigurationGeometry kCloseConfigurationGeometry;
};
}

#endif  // ANIMATION_GEOMETRY_SETTER_H
