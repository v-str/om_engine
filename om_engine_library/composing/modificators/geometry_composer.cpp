#include <geometry_composer.h>

#include <shifter.h>
#include <stretcher.h>

using namespace om_composing;

GeometryComposer::GeometryComposer(
    const ModificationFactor &modification_factor, Side modify_to,
    TransformationType type) {
  switch (type) {
    case kShifting:
      InitializeShifter();
      shifter_->SetModificationFactor(modification_factor);
      shifter_->ModifyTo(modify_to);
      break;

    case kStretching:
      InitializeStretcher();
      stretcher_->SetModificationFactor(modification_factor);
      stretcher_->ModifyTo(modify_to);
      break;

    default:
      break;
  }
}

void GeometryComposer::SetDeltaSize(const DeltaSize &delta_size) {
  if (shifter_ != nullptr) {
    shifter_->SetDeltaSize(delta_size);
  }
  if (stretcher_ != nullptr) {
    stretcher_->SetDeltaSize(delta_size);
  }
}

void GeometryComposer::InitializeShifter() {
  shifter_ = std::move(std::unique_ptr<GeometryModifier>(new Shifter));
}

void GeometryComposer::InitializeStretcher() {
  stretcher_ = std::move(std::unique_ptr<GeometryModifier>(new Stretcher));
}
