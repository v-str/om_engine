#include <date_label.h>

#include <om_utility.h>

using namespace om_widgets;
using namespace om_utility;

DateLabel::DateLabel(QWidget* parent) : AbstractClock(parent) {
  Update();
  InitializeTimer(this);
}

DateLabel::~DateLabel() {}

void DateLabel::Update() { TimeDateChanger::ChangeDate(this); }
