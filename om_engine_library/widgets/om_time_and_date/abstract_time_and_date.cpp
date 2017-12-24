#include <abstract_time_and_date.h>

om_widgets::AbstractTimeAndDate::AbstractTimeAndDate(QLabel* parent)
    : QLabel(parent) {
  setAlignment(Qt::AlignCenter);
}

unsigned int om_widgets::AbstractTimeAndDate::TimerTick() { return kTimerTick; }

void om_widgets::AbstractTimeAndDate::InitializeTimer(QLabel* label) {
  timer_ = new QTimer(label);
}
