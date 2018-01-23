#ifndef ANIMATION_GEOMETRY_SETTER_H
#define ANIMATION_GEOMETRY_SETTER_H

#include <memory>

#include <QPair>
#include <QRect>

#include <om_utility.h>

namespace om_animation {
class ConfigurationGeometry;

class AnimationGeometrySetter {
 public:
  static QPair<QRect, QRect> GetGeometryFor(
      const QRect& widget_geometry,
      om_utility::WidgetAnimationType animation_type,
      unsigned int animation_direction);

 private:
  static std::unique_ptr<ConfigurationGeometry> kOpenConfigurationGeometry;
  static std::unique_ptr<ConfigurationGeometry> kCloseConfigurationGeometry;
};
}

#endif  // ANIMATION_GEOMETRY_SETTER_H
