#include <abstract_time_and_date.h>

om_widgets::AbstractTimeAndDate::AbstractTimeAndDate(QLabel* parent)
    : QLabel(parent) {
  setAlignment(Qt::AlignCenter);
}

om_widgets::AbstractTimeAndDate::~AbstractTimeAndDate() {}

unsigned int om_widgets::AbstractTimeAndDate::TimerTick() { return kTimerTick; }

void om_widgets::AbstractTimeAndDate::InitializeTimer(QLabel* label) {
  timer_ = new QTimer(label);
}
