#ifndef GEOMETRY_COMPOSER_H
#define GEOMETRY_COMPOSER_H

#include <memory>

#include <geometry_modifier.h>
#include <om_utility.h>

namespace om_composing {
using namespace om_utility;

class GeometryComposer {
 public:
  GeometryComposer(const ModificationFactor& modification_factor,
                   Side modify_to = kRight,
                   TransformationType type = kShifting);

 private:
  std::unique_ptr<GeometryModifier> geometry_modifier_;
};
}

#endif  // GEOMETRY_COMPOSER_H
