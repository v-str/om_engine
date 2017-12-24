#include <abstract_time_and_date.h>

om_widgets::AbstractTimeAndDate::AbstractTimeAndDate(QLabel* parent)
    : QLabel(parent) {
  setAlignment(Qt::AlignCenter);
}

void om_widgets::AbstractTimeAndDate::RunUpdate() { Update(); }

unsigned int om_widgets::AbstractTimeAndDate::TimerTick() { return kTimerTick; }

void om_widgets::AbstractTimeAndDate::InitializeTimer(QLabel* label) {
  timer_ = new QTimer(label);
  timer_->start(kTimerTick);
  connect(timer_, SIGNAL(timeout()), SLOT(RunUpdate()));
}
