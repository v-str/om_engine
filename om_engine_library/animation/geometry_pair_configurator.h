#ifndef GEOMETRY_PAIR_CONFIGURATOR_H
#define GEOMETRY_PAIR_CONFIGURATOR_H

#include <QPair>
#include <QRect>

#include <om_utility.h>

namespace om_animation {
class GeometryPairConfigurator {
 public:
  static QPair<QRect, QRect> GetGeometryFor(
      om_utility::WidgetAnimationType type,
      unsigned int animation_direction,
      const QRect& widget_geometry);

 private:
  static QPair<QRect, QRect> geometry_pair_;
};
}
#endif  // GEOMETRY_PAIR_CONFIGURATOR_H
