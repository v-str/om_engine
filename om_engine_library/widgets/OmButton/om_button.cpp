#include <om_button.h>

om_widgets::OmButton::OmButton(QWidget* parent) : QPushButton(parent) {}

om_widgets::OmButton::OmButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

om_widgets::OmButton::~OmButton() {}

void om_widgets::OmButton::SetOffsetSide(unsigned int offset_side) {
  offset_side_ = offset_side;
}

void om_widgets::OmButton::SetOffsetDistance(
    const om_utility::OffsetDistance& offset_distance) {
  offset_distance_ = offset_distance;
}

void om_widgets::OmButton::enterEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & om_utility::kLeft) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & om_utility::kRight) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & om_utility::kUp) {
    y_pos -= offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & om_utility::kDown) {
    y_pos += offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}

void om_widgets::OmButton::leaveEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & om_utility::kLeft) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & om_utility::kRight) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & om_utility::kUp) {
    y_pos += offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & om_utility::kDown) {
    y_pos -= offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}
