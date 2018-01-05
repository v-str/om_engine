#include <geometry_composer.h>

#include <shifter.h>
#include <stretcher.h>

using namespace om_composing;

GeometryComposer::GeometryComposer(
    const ModificationFactor &modification_factor, Side modify_to,
    TransformationType type) {
  switch (type) {
    case kShifting:
      geometry_modifier_ =
          std::move(std::unique_ptr<GeometryModifier>(new Shifter));
      break;

    case kStretching:
      geometry_modifier_ =
          std::move(std::unique_ptr<GeometryModifier>(new Stretcher));
      break;

    default:
      break;
  }

  geometry_modifier_->SetModificationFactor(modification_factor);
  geometry_modifier_->ModifyTo(modify_to);
}

void GeometryComposer::SetDeltaSize(const DeltaSize &delta_size) {
  geometry_modifier_->SetDeltaSize(delta_size);
}
