#include <click_button.h>

#include <widgets_utility.h>

using namespace om_widgets;
using namespace widgets_utility;

ClickButton::ClickButton(QWidget* parent) : QPushButton(parent) {}

ClickButton::ClickButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

ClickButton::ClickButton(const QString& button_text,
                         const OffsetDistance& offset_distance,
                         unsigned int offset_side, QWidget* parent)
    : QPushButton(parent) {
  setText(button_text);
  SetOffsetParameters(offset_distance, offset_side);
}

ClickButton::~ClickButton() {}

void ClickButton::SetOffsetParameters(const OffsetDistance& offset_distance,
                                      unsigned int offset_side) {
  offset_distance_ = offset_distance;
  offset_side_ = offset_side;
}

void ClickButton::enterEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & kLeft) {
    x_pos -= offset_distance_.GetOffSetDistanceX();
  }
  if (offset_side_ & kRight) {
    x_pos += offset_distance_.GetOffSetDistanceX();
  }
  if (offset_side_ & kUp) {
    y_pos -= offset_distance_.GetOffSetDistanceY();
  }
  if (offset_side_ & kDown) {
    y_pos += offset_distance_.GetOffSetDistanceY();
  }
  move(x_pos, y_pos);
}

void ClickButton::leaveEvent(QEvent*) {
  int x_pos = x();
  int y_pos = y();
  if (offset_side_ & kLeft) {
    x_pos += offset_distance_.GetOffSetDistanceX();
  }
  if (offset_side_ & kRight) {
    x_pos -= offset_distance_.GetOffSetDistanceX();
  }
  if (offset_side_ & kUp) {
    y_pos += offset_distance_.GetOffSetDistanceY();
  }
  if (offset_side_ & kDown) {
    y_pos -= offset_distance_.GetOffSetDistanceY();
  }
  move(x_pos, y_pos);
}
