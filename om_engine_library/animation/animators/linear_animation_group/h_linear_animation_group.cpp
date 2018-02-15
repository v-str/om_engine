#include <h_linear_animation_group.h>

#include <QRect>
#include <QVariant>
#include <QWidget>

using namespace om_animation;

HLinearAnimationGroup::HLinearAnimationGroup(QWidget *parent, bool is_set_open,
                                     SlideDirection slide_direction,
                                     unsigned int distance_btw_widgets_px)
    : LinearAnimationGroup(parent, is_set_open),
      slide_direction_(slide_direction),
      distance_btw_widgets_px_(distance_btw_widgets_px) {}

HLinearAnimationGroup::~HLinearAnimationGroup() {}

void HLinearAnimationGroup::ComposeAnimation() {}
