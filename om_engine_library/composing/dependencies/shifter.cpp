#include <shifter.h>

#include <om_utility.h>

using namespace om_utility;
using namespace om_composing;

void Shifter::ComputeShifting(const QPoint &shift_point) {
  int x = shift_point.x();
  int y = shift_point.y();

  if (shift_side_ & Side::kLeft) {
    x -= shift_conversion_.X() * delta_size_.Width();
  }
  if (shift_side_ & Side::kRight) {
    x += shift_conversion_.X() * delta_size_.Width();
  }
  if (shift_side_ & Side::kUp) {
    y -= shift_conversion_.Y() * delta_size_.Height();
  }
  if (shift_side_ & Side::kDown) {
    y += shift_conversion_.Y() * delta_size_.Height();
  }

  shift_point_ = QPoint(x,y);
}

void Shifter::MakeShiftConversion(const ConversionMaker &shift_conversion) {
  shift_conversion_ = shift_conversion;
}

void Shifter::SetShiftSide(unsigned int shift_side) {
  shift_side_ = shift_side;
}

void Shifter::SetDeltaSize(const DeltaSize &delta_size) {
  delta_size_ = delta_size;
}

QPoint Shifter::GetShiftPoint() const { return shift_point_; }
