#include <geometry_composer.h>

#include <shifter.h>
#include <stretcher.h>

using namespace geometry_modification;

GeometryComposer::GeometryComposer(
    const ModificationFactor &modification_factor, unsigned int side_to_modify,
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
  geometry_modifier_->ModifyTo(side_to_modify);
}

void GeometryComposer::ComposeGeometry(const QRect &initial_widget_geometry,
                                       QWidget *widget) {
  geometry_modifier_->ComputeModification(initial_widget_geometry);
  widget->setGeometry(geometry_modifier_->GetModifiedRect());
}

void GeometryComposer::SetDeltaSize(const DeltaSize &delta_size) {
  geometry_modifier_->SetDeltaSize(delta_size);
}
