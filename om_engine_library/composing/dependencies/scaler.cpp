#include <scaler.h>

#include <QRect>

using namespace om_composing;

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
