﻿#ifndef OPEN_CONFIGURATION_GEOMETRY_H
#define OPEN_CONFIGURATION_GEOMETRY_H

#include <configuration_geometry.h>

namespace om_animation {
class OpenConfigurationGeometry : public ConfigurationGeometry {
 public:
  OpenConfigurationGeometry();
  ~OpenConfigurationGeometry();

  QPair<QRect, QRect> GetGeometryConfiguration(
      unsigned int animation_direction, const QRect& widget_geometry) override;

 private:
  unsigned int x_ = 0;
  unsigned int y_ = 0;
  unsigned int width_ = 0;
  unsigned int height_ = 0;
};
}

#endif  // OPEN_CONFIGURATION_GEOMETRY_H
