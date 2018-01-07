#include <geometry_scaler.h>

#include <om_utility.h>
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

void GeometryScaler::ScaleGeometry(const QRect &initial_widget_geometry,
                                   QWidget *widget) {
  shifter_->ComputeModification(initial_widget_geometry);
  QRect after_shifting_rect = shifter_->GetModifiedRect();

  stretcher_->ComputeModification(initial_widget_geometry);
  QRect after_stretching_rect = stretcher_->GetModifiedRect();

  widget->setGeometry(
      om_utility::AddRects(after_shifting_rect, after_stretching_rect));
}

void GeometryScaler::SetDeltaSize(const DeltaSize &delta_size) {
  shifter_->SetDeltaSize(delta_size);
  stretcher_->SetDeltaSize(delta_size);
}
