#include <om_button.h>

using namespace om_widgets;
using namespace om_utility;

OmButton::OmButton(QWidget* parent) : QPushButton(parent) {}

OmButton::OmButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

OmButton::~OmButton() {}

void OmButton::SetOffsetSide(unsigned int offset_side) {
  offset_side_ = offset_side;
}

void OmButton::SetOffsetDistance(const OffsetDistance& offset_distance) {
  offset_distance_ = offset_distance;
}

void OmButton::enterEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & kLeft) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & kRight) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & kUp) {
    y_pos -= offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & kDown) {
    y_pos += offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}

void OmButton::leaveEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & kLeft) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & kRight) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & kUp) {
    y_pos += offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & kDown) {
    y_pos -= offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}
