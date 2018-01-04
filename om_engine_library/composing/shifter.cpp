#include <shifter.h>

using namespace om_composing;

void Shifter::MakeShiftConversion(const ConversionMaker &shift_conversion) {
  shift_conversion_ = shift_conversion;
}

void Shifter::SetShiftSide(unsigned int shift_side) {
  shift_side_ = shift_side;
}

void Shifter::SetDeltaSize(const DeltaSize &delta_size) {
  delta_size_ = delta_size;
}

int Shifter::XPos() const { return x_pos_; }

int Shifter::YPos() const { return y_pos_; }
