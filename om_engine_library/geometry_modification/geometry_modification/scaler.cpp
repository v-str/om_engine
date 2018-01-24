#include <scaler.h>

#include <geometry_modifier.h>
#include <shifter.h>
#include <stretcher.h>

using namespace geometry_modification;

Scaler::Scaler() : shifter_(new Shifter), stretcher_(new Stretcher) {
  shifter_->SetModificationFactor(ModificationFactor(0.0, 0.0));
  shifter_->ModifyTo(kLeft);
  stretcher_->SetModificationFactor(ModificationFactor(0.0, 0.0));
  stretcher_->ModifyTo(kLeft);
}

Scaler::Scaler(const ModificationFactor &modification_shift_factor,
               const ModificationFactor &modification_stretch_factor,
               Side shift_to, Side stretch_to)
    : shifter_(new Shifter), stretcher_(new Stretcher) {
  shifter_->SetModificationFactor(modification_shift_factor);
  shifter_->ModifyTo(shift_to);
  stretcher_->SetModificationFactor(modification_stretch_factor);
  stretcher_->ModifyTo(stretch_to);
}

Scaler::~Scaler() {}

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

void Scaler::SetDeltaSize(DeltaSize &&delta_size) {
  shifter_->SetDeltaSize(std::move(delta_size));
  stretcher_->SetDeltaSize(std::move(delta_size));
}

void Scaler::SetScalingFactor(const ModificationFactor &factor_for_shift,
                              const ModificationFactor &factor_for_stretch) {
  shifter_->SetModificationFactor(factor_for_shift);
  stretcher_->SetModificationFactor(factor_for_stretch);
}

void Scaler::SetShiftFactor(const ModificationFactor &factor_for_shift) {
  shifter_->SetModificationFactor(factor_for_shift);
}

void Scaler::SetStretchFactor(const ModificationFactor &factor_for_stretch) {
  stretcher_->SetModificationFactor(factor_for_stretch);
}

void Scaler::ScaleTo(unsigned int shift_to, unsigned int stretch_to) {
  shifter_->ModifyTo(shift_to);
  stretcher_->ModifyTo(stretch_to);
}

void Scaler::ShiftTo(unsigned int shift_to) { shifter_->ModifyTo(shift_to); }

void Scaler::StretchTo(unsigned int stretch_to) {
  stretcher_->ModifyTo(stretch_to);
}
