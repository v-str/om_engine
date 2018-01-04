#ifndef SHIFTER_H
#define SHIFTER_H

#include <conversion_maker.h>
#include <delta_size.h>

namespace om_composing {

class Shifter {
 public:
  void MakeShiftConversion(const ConversionMaker& shift_conversion);
  void SetShiftSide(unsigned int shift_side);
  void SetDeltaSize(const DeltaSize& delta_size);

  int XPos() const;
  int YPos() const;

 private:
  ConversionMaker shift_conversion_;
  DeltaSize delta_size_;

  unsigned int shift_side_ = 0;

  int x_pos_ = 0;
  int y_pos_ = 0;
};
}

#endif  // SHIFTER_H
