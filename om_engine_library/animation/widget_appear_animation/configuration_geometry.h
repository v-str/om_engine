#ifndef CONFIGURATION_GEOMETRY_H
#define CONFIGURATION_GEOMETRY_H

#include <QPair>
#include <QRect>

namespace om_animation {
class ConfigurationGeometry {
 public:
  virtual QPair<QRect, QRect> GetGeometryConfiguration(
      unsigned int animation_direction, const QRect& widget_geometry) = 0;

  void InitializeParameters(unsigned int& x,
                            unsigned int& y,
                            unsigned int& width,
                            unsigned int& height,
                            const QRect& widget_geometry);
};
}

#endif  // CONFIGURATION_GEOMETRY_H
