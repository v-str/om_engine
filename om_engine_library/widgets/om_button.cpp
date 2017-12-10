#include <om_button.h>

OmWidgets::OmButton::OmButton(QWidget* parent) : QPushButton(parent) {}

OmWidgets::OmButton::OmButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

OmWidgets::OmButton::~OmButton() {}

void OmWidgets::OmButton::SetOffsetSide(unsigned int offset_side) {
  offset_side_ = offset_side;
}

void OmWidgets::OmButton::SetOffsetDistance(
    const OmUtility::OffsetDistance& offset_distance) {
  offset_distance_ = offset_distance;
}

void OmWidgets::OmButton::enterEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & OmUtility::kLeft) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kRight) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kUp) {
    y_pos -= offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & OmUtility::kDown) {
    y_pos += offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}

void OmWidgets::OmButton::leaveEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & OmUtility::kLeft) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kRight) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kUp) {
    y_pos += offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & OmUtility::kDown) {
    y_pos -= offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}
