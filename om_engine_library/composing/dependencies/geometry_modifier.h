#ifndef GEOMETRY_MODIFIER_H
#define GEOMETRY_MODIFIER_H

#include <QRect>

#include <conversion_maker.h>
#include <delta_size.h>

namespace om_composing {

class GeometryModifier {
 public:
  virtual void ComputeModification(const QRect& initial_position) = 0;

  void SetModificationConversion(
      const ConversionMaker& modification_converstion) {
    modification_converstion_ = modification_converstion;
  }

  void SetDeltaSize(const DeltaSize& delta_size) { delta_size_ = delta_size; }

  void ModifyTo(unsigned int modified_side) { modified_side_ = modified_side; }

 protected:
  ConversionMaker modification_converstion_;
  DeltaSize delta_size_;

  unsigned int modified_side_ = 0;
};
}

#endif  // GEOMETRY_MODIFIER_H
