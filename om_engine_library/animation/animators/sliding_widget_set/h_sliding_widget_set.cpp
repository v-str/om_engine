#include <h_sliding_widget_set.h>

#include <QRect>
#include <QVariant>
#include <QWidget>

using namespace om_animation;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent,
                                     SlideDirection slide_direction,
                                     unsigned int distance_between_widgets_px,
                                     bool is_set_open)
    : AbstractSlidingWidgetSet(parent, is_set_open) {}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::ComposeAnimation() {}
