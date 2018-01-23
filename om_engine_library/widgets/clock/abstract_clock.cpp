#include <abstract_clock.h>

#include <QTimer>

using namespace om_widgets;

AbstractClock::AbstractClock(QWidget* parent) : QLabel(parent) {
  setAlignment(Qt::AlignCenter);
}

AbstractClock::~AbstractClock() {}

void AbstractClock::RunUpdate() { Update(); }

unsigned int AbstractClock::TimerTick() { return kOneSecondTick; }

void AbstractClock::InitializeTimer(QLabel* label) {
  timer_ = new QTimer(label);
  timer_->start(kOneSecondTick);
  connect(timer_, SIGNAL(timeout()), SLOT(RunUpdate()));
}
