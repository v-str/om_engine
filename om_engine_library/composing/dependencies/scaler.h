#ifndef SCALER_H
#define SCALER_H

#include <memory>

#include <om_utility.h>
#include <shifter.h>
#include <stretcher.h>

class QRect;

namespace om_composing {
using namespace om_utility;

class Scaler : public Shifter, public Stretcher {
 public:
  Scaler();
  Scaler(const ModificationFactor& modification_shift_factor,
         const ModificationFactor& modification_stretch_factor,
         Side shift_to = kRight, Side stretch_to = kRight);

  void ComputeModification(const QRect& initial_position) override;
  QRect GetModifiedRect() const override;
  void SetDeltaSize(const DeltaSize& delta_size) override;

  void SetModificationFactor(const ModificationFactor& factor_for_shift,
                             const ModificationFactor& factor_for_stretch);

 private:
  std::unique_ptr<Shifter> shifter_;
  std::unique_ptr<Stretcher> stretcher_;
};
}

#endif  // SCALER_H
