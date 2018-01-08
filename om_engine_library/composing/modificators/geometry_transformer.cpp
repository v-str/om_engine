#include <geometry_transformer.h>

#include <QRect>
#include <QWidget>

#include <shifter.h>
#include <stretcher.h>

using namespace om_composing;

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
    Side stretch_to) {}
