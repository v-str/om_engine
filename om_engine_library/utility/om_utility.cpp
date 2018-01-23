#include <om_utility.h>

#include <QDate>
#include <QLabel>
#include <QRect>
#include <QTime>

using namespace om_utility;

void TimeDateChanger::ChangeTime(QLabel* time_label) {
  time_label->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void TimeDateChanger::ChangeDate(QLabel* date_label) {
  date_label->setText(QDate::currentDate().toString("dd.MM.yy"));
}
