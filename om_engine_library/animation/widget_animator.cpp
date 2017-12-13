#include <widget_animator.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QTimer>
#include <QWidget>

om_animation::WidgetAnimator::WidgetAnimator(QWidget* widget)
    : QObject(widget),
      property_animation_(new QPropertyAnimation(widget, "geometry", this)) {}

om_animation::WidgetAnimator::~WidgetAnimator() {}

void om_animation::WidgetAnimator::SetAnimation(
    WidgetAnimationType widget_animation_type,
    const QEasingCurve& curve,
    unsigned int animation_duration_msec,
    unsigned int animation_direction) {
  widget_animation_type_ = widget_animation_type;
  property_animation_->setEasingCurve(curve);
  property_animation_->setDuration(animation_duration_msec);
  animation_direction_ = animation_direction;
}
