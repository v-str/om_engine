#include <scaler.h>

#include <QRect>

using namespace om_utility;
using namespace geometry_modification;

Scaler::Scaler() {
  shifter_ = std::make_unique<Shifter>();
  stretcher_ = std::make_unique<Stretcher>();

  shifter_->SetModificationFactor(ModificationFactor(0.0, 0.0));
  shifter_->ModifyTo(kLeft);
  stretcher_->SetModificationFactor(ModificationFactor(0.0, 0.0));
  stretcher_->ModifyTo(kLeft);
}

Scaler::Scaler(const ModificationFactor &modification_shift_factor,
               const ModificationFactor &modification_stretch_factor,
               Side shift_to, Side stretch_to) {
  shifter_->SetModificationFactor(modification_shift_factor);
  shifter_->ModifyTo(shift_to);

  stretcher_->SetModificationFactor(modification_stretch_factor);
  stretcher_->ModifyTo(stretch_to);
}

void Scaler::ComputeModification(const QRect &initial_position) {
  shifter_->ComputeModification(initial_position);
  stretcher_->ComputeModification(initial_position);
}

QRect Scaler::GetModifiedRect() const {
  return QRect(shifter_->GetModifiedRect().x(), shifter_->GetModifiedRect().y(),
               stretcher_->GetModifiedRect().width(),
               stretcher_->GetModifiedRect().height());
}

void Scaler::SetDeltaSize(const DeltaSize &delta_size) {
  shifter_->SetDeltaSize(delta_size);
  stretcher_->SetDeltaSize(delta_size);
}

void Scaler::SetModificationFactor(
    const ModificationFactor &factor_for_shift,
    const ModificationFactor &factor_for_stretch) {
  shifter_->SetModificationFactor(factor_for_shift);
  stretcher_->SetModificationFactor(factor_for_stretch);
}

void Scaler::ModifyTo(unsigned int side_for_shift,
                      unsigned int side_for_stretch) {
  shifter_->ModifyTo(side_for_shift);
  stretcher_->ModifyTo(side_for_stretch);
}
