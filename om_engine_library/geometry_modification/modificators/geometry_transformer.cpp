#include <geometry_transformer.h>

#include <QRect>
#include <QWidget>

#include <scaler.h>
#include <shifter.h>
#include <stretcher.h>

using namespace geometry_modification;

GeometryTransformer::GeometryTransformer(
    const ModificationFactor &modification_factor, unsigned int side_to_modify,
    TransformationType type) {
  switch (type) {
    case kShifting:
      composer_ = std::move(std::unique_ptr<GeometryModifier>(new Shifter));
      break;

    case kStretching:
      composer_ = std::move(std::unique_ptr<GeometryModifier>(new Stretcher));
      break;

    default:
      break;
  }

  composer_->SetModificationFactor(modification_factor);
  composer_->ModifyTo(side_to_modify);
}

GeometryTransformer::GeometryTransformer(
    const ModificationFactor &modification_shift_factor,
    const ModificationFactor &modification_stretch_factor, Side shift_to,
    Side stretch_to) {
  scaler_ = std::move(std::unique_ptr<GeometryModifier>(
      new Scaler(modification_shift_factor, modification_stretch_factor,
                 shift_to, stretch_to)));


}
