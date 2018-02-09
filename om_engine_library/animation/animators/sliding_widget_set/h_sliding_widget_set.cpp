#include <h_sliding_widget_set.h>

#include <QWidget>

using namespace om_animaiton;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent, bool is_set_open)
    : AbstractSlidingWidgetSet(parent, is_set_open) {}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::SetStartAnimationPosition() {}

void HSlidingWidgetSet::SetEndAnimationPosition() {}
