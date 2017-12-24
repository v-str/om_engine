#include <om_time_label.h>

#include <om_utility.h>

using namespace om_widgets;
using namespace om_utility;

OmTimeLabel::OmTimeLabel(QLabel* parent) : AbstractTimeAndDate(parent) {
  Update();
  InitializeTimer(this);
}

OmTimeLabel::~OmTimeLabel() {}

void OmTimeLabel::Update() { om_utility::TimeDateChanger::ChangeTime(this); }
