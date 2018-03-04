#include <shifter.h>

using namespace scaling;

Shifter::Shifter() : GeometryModifier() {}

Shifter::~Shifter() {}

void Shifter::ComputeModification(const QRect &initial_position) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (modified_side_ & Side::kLeft) {
    x -= axes_ratio_.X() * delta_size_.Width();
  }
  if (modified_side_ & Side::kRight) {
    x += axes_ratio_.X() * delta_size_.Width();
  }
  if (modified_side_ & Side::kUp) {
    y -= axes_ratio_.Y() * delta_size_.Height();
  }
  if (modified_side_ & Side::kDown) {
    y += axes_ratio_.Y() * delta_size_.Height();
  }

  shifted_rect_ =
      QRect(x, y, initial_position.width(), initial_position.height());
}

QRect Shifter::GetModifiedRect() const { return shifted_rect_; }
