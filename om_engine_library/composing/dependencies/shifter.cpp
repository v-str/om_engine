#include <shifter.h>

#include <om_utility.h>

using namespace om_utility;
using namespace om_composing;

void Shifter::ComputeModification(const QRect &initial_position) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (modified_side_ & Side::kLeft) {
    x -= modification_converstion_.X() * delta_size_.Width();
  }
  if (modified_side_ & Side::kRight) {
    x += modification_converstion_.X() * delta_size_.Width();
  }
  if (modified_side_ & Side::kUp) {
    y -= modification_converstion_.Y() * delta_size_.Height();
  }
  if (modified_side_ & Side::kDown) {
    y += modification_converstion_.Y() * delta_size_.Height();
  }

  shift_point_ = QPoint(x, y);
}

QPoint Shifter::GetShiftPoint() const { return shift_point_; }
