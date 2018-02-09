#include <h_sliding_widget_set.h>

#include <QWidget>

using namespace om_animaiton;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent, bool is_set_open,
                                     SlideDirection slide_direction)
    : AbstractSlidingWidgetSet(parent, is_set_open),
      slide_direction_(slide_direction) {}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::SetStartAnimationPosition() {}

void HSlidingWidgetSet::SetEndAnimationPosition() {}
