#include <configuration_geometry.h>

void om_animation::ConfigurationGeometry::InitializeParameters(
    unsigned int& x,
    unsigned int& y,
    unsigned int& width,
    unsigned int& height,
    const QRect& widget_geometry) {
  x = widget_geometry.x();
  y = widget_geometry.y();
  width = widget_geometry.width();
  height = widget_geometry.height();
}
