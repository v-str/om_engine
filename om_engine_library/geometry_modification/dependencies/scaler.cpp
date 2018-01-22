#include <scaler.h>

#include <QRect>

using namespace om_utility;
using namespace om_composing;

Scaler::Scaler() {
  Shifter::SetModificationFactor(ModificationFactor(0.0, 0.0));
  Shifter::ModifyTo(kLeft);
  Stretcher::SetModificationFactor(ModificationFactor(0.0, 0.0));
  Stretcher::ModifyTo(kLeft);
}

Scaler::Scaler(const ModificationFactor &modification_shift_factor,
               const ModificationFactor &modification_stretch_factor,
               Side shift_to, Side stretch_to) {
  Shifter::SetModificationFactor(modification_shift_factor);
  Shifter::ModifyTo(shift_to);

  Stretcher::SetModificationFactor(modification_stretch_factor);
  Stretcher::ModifyTo(stretch_to);
}

void Scaler::ComputeModification(const QRect &initial_position) {
  Shifter::ComputeModification(initial_position);
  Stretcher::ComputeModification(initial_position);
}

QRect Scaler::GetModifiedRect() const {
  return QRect(Shifter::GetModifiedRect().x(), Shifter::GetModifiedRect().y(),
               Stretcher::GetModifiedRect().width(),
               Stretcher::GetModifiedRect().height());
}

void Scaler::SetDeltaSize(const DeltaSize &delta_size) {
  Shifter::SetDeltaSize(delta_size);
  Stretcher::SetDeltaSize(delta_size);
}

void Scaler::SetModificationFactor(
    const ModificationFactor &factor_for_shift,
    const ModificationFactor &factor_for_stretch) {
  Shifter::SetModificationFactor(factor_for_shift);
  Stretcher::SetModificationFactor(factor_for_stretch);
}

void Scaler::ModifyTo(unsigned int side_for_shift,
                      unsigned int side_for_stretch) {
  Shifter::ModifyTo(side_for_shift);
  Stretcher::ModifyTo(side_for_stretch);
}
