#include <shifter.h>

#include <om_utility.h>

using namespace om_utility;
using namespace geometry_modification;

Shifter::Shifter() : GeometryModifier() {}

Shifter::~Shifter() {}

void Shifter::ComputeModification(const QRect &initial_position) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (modified_side_ & Side::kLeft) {
    x -= modification_factor_.X() * delta_size_.Width();
  }
  if (modified_side_ & Side::kRight) {
    x += modification_factor_.X() * delta_size_.Width();
  }
  if (modified_side_ & Side::kUp) {
    y -= modification_factor_.Y() * delta_size_.Height();
  }
  if (modified_side_ & Side::kDown) {
    y += modification_factor_.Y() * delta_size_.Height();
  }

  shifted_rect_ =
      QRect(x, y, initial_position.width(), initial_position.height());
}

QRect Shifter::GetModifiedRect() const { return shifted_rect_; }
