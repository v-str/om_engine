#include <geometry_scaler.h>

#include <shifter.h>
#include <stretcher.h>

using namespace geometry_modification;

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
  stretcher_->ComputeModification(initial_widget_geometry);
  widget->setGeometry(
      AddRects(shifter_->GetModifiedRect(), stretcher_->GetModifiedRect()));
}

void GeometryScaler::SetDeltaSize(const DeltaSize &delta_size) {
  shifter_->SetDeltaSize(delta_size);
  stretcher_->SetDeltaSize(delta_size);
}

QRect GeometryScaler::AddRects(const QRect &shifted_geometry,
                               const QRect &stretched_geometry) {
  return QRect(shifted_geometry.x(), shifted_geometry.y(),
               stretched_geometry.width(), stretched_geometry.height());
}
