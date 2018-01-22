#include <stretcher.h>

#include <om_utility.h>

using namespace om_utility;
using namespace geometry_modification;

void Stretcher::ComputeModification(const QRect &initial_position) {
  int x_pos = initial_position.x();
  int y_pos = initial_position.y();
  int width = initial_position.width();
  int height = initial_position.height();

  if (modified_side_ & Side::kLeft) {
    width += (modification_factor_.X() * delta_size_.Width());
    x_pos -= (modification_factor_.X() * delta_size_.Width());
  }
  if (modified_side_ & Side::kRight) {
    width += (modification_factor_.X() * delta_size_.Width());
  }
  if (modified_side_ & Side::kDown) {
    height += (modification_factor_.Y() * delta_size_.Height());
  }
  if (modified_side_ & Side::kUp) {
    height += (modification_factor_.Y() * delta_size_.Height());
    y_pos -= (modification_factor_.Y() * delta_size_.Height());
  }

  stretched_rect_ = QRect(x_pos, y_pos, width, height);
}

QRect Stretcher::GetModifiedRect() const { return stretched_rect_; }
