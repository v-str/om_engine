#ifndef CLOSE_CONFIGURATION_GEOMETRY_H
#define CLOSE_CONFIGURATION_GEOMETRY_H

#include <configuration_geometry.h>

namespace om_animation {
class CloseConfigurationGeometry : public ConfigurationGeometry {
 public:
  QPair<QRect, QRect> GetGeometryConfiguration(
      unsigned int animation_direction, const QRect& widget_geometry) override;

 private:
  unsigned int x_ = 0;
  unsigned int y_ = 0;
  unsigned int width_ = 0;
  unsigned int height_ = 0;
};
}

#endif  // CLOSE_CONFIGURATION_GEOMETRY_H
