#ifndef SHIFTER_H
#define SHIFTER_H

#include <QPoint>
#include <QRect>

#include <conversion_maker.h>
#include <delta_size.h>

namespace om_composing {

class Shifter {
 public:
  void ComputeShifting(const QRect& shift_position);

  void SetShiftConversion(const ConversionMaker& shift_conversion);
  void SetShiftSide(unsigned int shift_side);
  void SetDeltaSize(const DeltaSize& delta_size);

  QPoint GetShiftPoint() const;

 private:
  ConversionMaker shift_conversion_;
  DeltaSize delta_size_;

  unsigned int shift_side_ = 0;

  QPoint shift_point_;
};
}

#endif  // SHIFTER_H
