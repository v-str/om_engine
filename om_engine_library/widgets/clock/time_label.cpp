#include <time_label.h>

#include <om_utility.h>

using namespace om_widgets;
using namespace om_utility;

TimeLabel::TimeLabel(QWidget* parent) : AbstractClock(parent) {
  Update();
  InitializeTimer(this);
}

TimeLabel::~TimeLabel() {}

void TimeLabel::Update() { TimeDateChanger::ChangeTime(this); }
