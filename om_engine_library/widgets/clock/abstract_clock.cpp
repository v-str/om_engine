#include <abstract_clock.h>

using namespace om_widgets;

AbstractClock::AbstractClock(QWidget* parent) : QLabel(parent) {
  setAlignment(Qt::AlignCenter);
}

void AbstractClock::RunUpdate() { Update(); }

unsigned int AbstractClock::TimerTick() { return kTimerTick; }

void AbstractClock::InitializeTimer(QLabel* label) {
  timer_ = new QTimer(label);
  timer_->start(kTimerTick);
  connect(timer_, SIGNAL(timeout()), SLOT(RunUpdate()));
}
