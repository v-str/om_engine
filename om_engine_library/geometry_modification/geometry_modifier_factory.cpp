#include <geometry_modifier_factory.h>

#include <scaler.h>
#include <shifter.h>
#include <stretcher.h>

using namespace om_utility;
using namespace geometry_modification;

GeometryModifier *GeometryModifierFactory::Create(TransformationType &type) {
  switch (type) {
    case kShifting:
      return new Shifter();
      break;
    case kStretching:
      return new Stretcher();
      break;
    case kScaling:
      return new Scaler();
    default:
      return nullptr;
      break;
  }
}
