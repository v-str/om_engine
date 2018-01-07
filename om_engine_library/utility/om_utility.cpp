#include <om_utility.h>

#include <QDate>
#include <QLabel>
#include <QRect>
#include <QTime>

om_utility::OffsetDistance::OffsetDistance(unsigned int offset_by_x,
                                           unsigned int offset_by_y)
    : offset_by_x_(offset_by_x), offset_by_y_(offset_by_y) {}

unsigned int om_utility::OffsetDistance::OffSetDistanceX() const {
  return offset_by_x_;
}

unsigned int om_utility::OffsetDistance::OffSetDistanceY() const {
  return offset_by_y_;
}

void om_utility::TimeDateChanger::ChangeTime(QLabel* time_label) {
  time_label->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void om_utility::TimeDateChanger::ChangeDate(QLabel* date_label) {
  date_label->setText(QDate::currentDate().toString("dd.MM.yy"));
}

QRect om_utility::AddRects(const QRect& rect1, const QRect& rect2) {
  QRect temp_rect;

  temp_rect.setX(rect1.x() + rect2.x());
  temp_rect.setY(rect1.y() + rect2.y());
  temp_rect.setWidth(rect1.width() + rect2.width());
  temp_rect.setHeight(rect1.height() + rect2.height());

  return temp_rect;
}
