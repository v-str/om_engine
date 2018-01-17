#include <om_utility.h>

#include <QDate>
#include <QLabel>
#include <QRect>
#include <QTime>

using namespace om_utility;

OffsetDistance::OffsetDistance(unsigned int offset_by_x,
                               unsigned int offset_by_y)
    : offset_by_x_(offset_by_x), offset_by_y_(offset_by_y) {}

unsigned int OffsetDistance::OffSetDistanceX() const { return offset_by_x_; }

unsigned int OffsetDistance::OffSetDistanceY() const { return offset_by_y_; }

void TimeDateChanger::ChangeTime(QLabel* time_label) {
  time_label->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void TimeDateChanger::ChangeDate(QLabel* date_label) {
  date_label->setText(QDate::currentDate().toString("dd.MM.yy"));
}
