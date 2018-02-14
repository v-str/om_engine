#include <h_sliding_widget_set.h>

#include <QRect>
#include <QVariant>
#include <QWidget>

using namespace om_animation;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent, bool is_set_open,
                                     SlideDirection slide_direction,
                                     unsigned int distance_btw_widgets_px)
    : AbstractSlidingWidgetSet(parent, is_set_open),
      slide_direction_(slide_direction),
      distance_btw_widgets_px_(distance_btw_widgets_px) {}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::ComposeAnimation() {}
