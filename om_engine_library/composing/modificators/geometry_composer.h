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

  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  void InitializeShifter();
  void InitializeStretcher();

  std::unique_ptr<GeometryModifier> shifter_;
  std::unique_ptr<GeometryModifier> stretcher_;
};
}

#endif  // GEOMETRY_COMPOSER_H
