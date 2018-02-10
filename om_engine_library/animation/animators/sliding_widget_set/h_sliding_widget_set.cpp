#include <h_sliding_widget_set.h>

#include <QRect>
#include <QWidget>

#include <h_animation_value_setter.h>

#include <QDebug>

using namespace om_animation;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent,
                                     unsigned int distance_between_widgets_px,
                                     bool is_set_open,
                                     SlideDirection slide_direction)
    : AbstractSlidingWidgetSet(parent, is_set_open),
      value_setter_(new HAnimationValueSetter(
          GetAnimationSet(), slide_direction, distance_between_widgets_px)) {
  qDebug() << "HSlidingWidgetSet: " << distance_between_widgets_px;
}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::AppointAnimationParameters() {
  value_setter_->SetStartValue();
  value_setter_->SetEndValue();
}
