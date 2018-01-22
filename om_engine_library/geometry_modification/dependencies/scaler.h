#ifndef SCALER_H
#define SCALER_H

#include <om_utility.h>
#include <shifter.h>
#include <stretcher.h>

class QRect;

namespace geometry_modification {

class Scaler : public Shifter, public Stretcher {
 public:
  Scaler();
  Scaler(const ModificationFactor& modification_shift_factor,
         const ModificationFactor& modification_stretch_factor,
         om_utility::Side shift_to = om_utility::kRight,
         om_utility::Side stretch_to = om_utility::kRight);

  void ComputeModification(const QRect& initial_position) override;
  QRect GetModifiedRect() const override;
  void SetDeltaSize(const DeltaSize& delta_size) override;

  void SetModificationFactor(const ModificationFactor& factor_for_shift,
                             const ModificationFactor& factor_for_stretch);
  void ModifyTo(unsigned int side_for_shift, unsigned int side_for_stretch);
};
}

#endif  // SCALER_H
