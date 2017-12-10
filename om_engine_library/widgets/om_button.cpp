#include <om_button.h>

using namespace OmUtility;

OmButton::OmButton(QWidget* parent) : QPushButton(parent) {}

OmButton::OmButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

OmButton::~OmButton() {}

void OmButton::SetOffsetSide(const Side& side) { offset_side_ = side; }

void OmButton::SetOffsetDistance(const OffsetDistance& offset_distance) {
  offset_distance_ = offset_distance;
}

void OmButton::enterEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & OmUtility::kLeft) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kRight) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kUp) {
    x_pos -= offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & OmUtility::kDown) {
    x_pos += offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}

void OmButton::leaveEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & OmUtility::kLeft) {
    x_pos += offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kRight) {
    x_pos -= offset_distance_.OffSetDistanceX();
  }
  if (offset_side_ & OmUtility::kUp) {
    x_pos += offset_distance_.OffSetDistanceY();
  }
  if (offset_side_ & OmUtility::kDown) {
    x_pos -= offset_distance_.OffSetDistanceY();
  }
  move(x_pos, y_pos);
}
