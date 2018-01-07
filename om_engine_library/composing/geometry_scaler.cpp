#include <geometry_scaler.h>

#include <shifter.h>
#include <stretcher.h>

using namespace om_composing;

GeometryScaler::GeometryScaler(
    const ModificationFactor &modification_shift_factor,
    const ModificationFactor &modification_stretch_factor, Side shift_to,
    Side stretch_to) {
  shifter_ = std::move(std::unique_ptr<GeometryModifier>(new Shifter));
  shifter_->SetModificationFactor(modification_shift_factor);
  shifter_->ModifyTo(shift_to);

  stretcher_ = std::move(std::unique_ptr<GeometryModifier>(new Stretcher));
  stretcher_->SetModificationFactor(modification_stretch_factor);
  stretcher_->ModifyTo(stretch_to);
}
