#include <abstract_clock.h>

om_widgets::AbstractClock::AbstractClock(QWidget* parent) : QLabel(parent) {
  setAlignment(Qt::AlignCenter);
}

void om_widgets::AbstractClock::RunUpdate() { Update(); }

unsigned int om_widgets::AbstractClock::TimerTick() { return kTimerTick; }

void om_widgets::AbstractClock::InitializeTimer(QLabel* label) {
  timer_ = new QTimer(label);
  timer_->start(kTimerTick);
  connect(timer_, SIGNAL(timeout()), SLOT(RunUpdate()));
}
