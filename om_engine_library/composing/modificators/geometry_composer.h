#ifndef GEOMETRY_COMPOSER_H
#define GEOMETRY_COMPOSER_H

#include <memory>

#include <QRect>
#include <QWidget>

#include <geometry_modifier.h>
#include <om_utility.h>

namespace om_composing {
using namespace om_utility;

class GeometryComposer {
 public:
  GeometryComposer(const ModificationFactor& modification_factor,
                   Side modify_to = kRight,
                   TransformationType type = kShifting);

  void ComposeGeometry(const QRect& initial_widget_geometry, QWidget* widget);

  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  std::unique_ptr<GeometryModifier> geometry_modifier_;

  QRect modified_geometry_;
};
}

#endif  // GEOMETRY_COMPOSER_H
