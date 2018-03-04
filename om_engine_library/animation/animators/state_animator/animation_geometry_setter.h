#ifndef ANIMATION_GEOMETRY_SETTER_H
#define ANIMATION_GEOMETRY_SETTER_H

#include <memory>

#include <QPair>
#include <QRect>

#include <animation_utility.h>

namespace om_animation {
class ConfigurationGeometry;

typedef std::unique_ptr<ConfigurationGeometry> Geometry;

class AnimationGeometrySetter {
 public:
  static QPair<QRect, QRect> GetGeometryFor(const QRect& widget_geometry,
                                            WidgetAnimationType animation_type,
                                            unsigned int animation_direction);

 private:
  static Geometry kOpenGeometry;
  static Geometry kCloseGeometry;
};
}

#endif  // ANIMATION_GEOMETRY_SETTER_H
