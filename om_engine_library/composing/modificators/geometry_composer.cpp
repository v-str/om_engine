#include <geometry_composer.h>

#include <shifter.h>
#include <stretcher.h>

using namespace om_composing;

GeometryComposer::GeometryComposer(
    const ModificationFactor &modification_factor, TransformationType type) {
  switch (type) {
    case kShifting:
      InitializeShifter();
      shifter_->SetModificationFactor(modification_factor);
      break;
    default:
      break;
  }
}

void GeometryComposer::InitializeShifter() {
  shifter_ = std::move(std::unique_ptr<GeometryModifier>(new Shifter));
}
