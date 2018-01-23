#ifndef SCALER_H
#define SCALER_H

#include <memory>

#include <QRect>

#include <om_utility.h>

namespace geometry_modification {
class GeometryModifier;
class ModificationFactor;
class DeltaSize;

class Scaler {
 public:
  Scaler();
  Scaler(const ModificationFactor &modification_shift_factor,
         const ModificationFactor &modification_stretch_factor,
         om_utility::Side shift_to, om_utility::Side stretch_to);
  ~Scaler();

  void SetDeltaSize(const DeltaSize &delta_size);
  void SetScalingFactor(const ModificationFactor &factor_for_shift,
                        const ModificationFactor &factor_for_stretch);
  void SetShiftFactor(const ModificationFactor &factor_for_shift);
  void SetStretchFactor(const ModificationFactor &factor_for_stretch);

  void ScaleTo(unsigned int shift_to, unsigned int stretch_to);
  void ShiftTo(unsigned int shift_to);
  void StretchTo(unsigned int stretch_to);

  void ComputeModification(const QRect &initial_position);
  QRect GetModifiedRect() const;

 private:
  std::unique_ptr<GeometryModifier> shifter_;
  std::unique_ptr<GeometryModifier> stretcher_;
};
}

#endif  // SCALER_H
