#include <date_label.h>

#include <om_utility.h>

using namespace om_widgets;
using namespace om_utility;

OmDateLabel::OmDateLabel(QWidget* parent) : AbstractClock(parent) {
  Update();
  InitializeTimer(this);
}

void OmDateLabel::Update() { TimeDateChanger::ChangeDate(this); }
