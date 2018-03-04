#include <time_label.h>

#include <QTime>

using namespace om_widgets;

TimeLabel::TimeLabel(QWidget* parent) : AbstractClock(parent) {
  Update();
  InitializeTimer(this);
}

TimeLabel::~TimeLabel() {}

void TimeLabel::Update() { setText(QTime::currentTime().toString("hh:mm:ss")); }
