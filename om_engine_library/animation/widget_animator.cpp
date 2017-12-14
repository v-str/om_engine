#include <widget_animator.h>

#include <QTimer>

#include <animation_geometry_setter.h>

om_animation::WidgetAnimator::WidgetAnimator(QWidget* widget)
    : QObject(), animation_(new QPropertyAnimation(widget, "geometry", this)) {}

om_animation::WidgetAnimator::~WidgetAnimator() {}

void om_animation::WidgetAnimator::SetAnimation(
    WidgetAnimationType widget_animation_type,
    const QEasingCurve& curve,
    unsigned int animation_duration_msec,
    unsigned int animation_direction) {
  widget_animation_type_ = widget_animation_type;
  animation_->setEasingCurve(curve);
  animation_->setDuration(animation_duration_msec);
  animation_direction_ = animation_direction;
}

void om_animation::WidgetAnimator::SetCurrentGeometry(
    const QRect& widget_geometry) {
  widget_geometry_ = widget_geometry;
}

void om_animation::WidgetAnimator::Close() {
  animation_geometry_ = AnimationGeometrySetter::GetAnimationForClosing(
      animation_direction_, widget_geometry_);
  RunAnimation(0, animation_duration_msec_);
}

void om_animation::WidgetAnimator::Open() {
  animation_geometry_ = AnimationGeometrySetter::GetAnimationForOpening(
      animation_direction_, widget_geometry_);
  RunAnimation(animation_duration_msec_, animation_duration_msec_);
}

void om_animation::WidgetAnimator::StartAnimationProcess() {
  animation_->start();
}

void om_animation::WidgetAnimator::EndAnimationProcess() {
  emit AnimationComplete();
}

void om_animation::WidgetAnimator::RunAnimation(
    unsigned int duration_start_msec, unsigned int duration_end_msec) {
  animation_->setStartValue(animation_geometry_.first);
  animation_->setEndValue(animation_geometry_.second);
  QTimer::singleShot(duration_start_msec, this, SLOT(StartAnimationProcess()));
  QTimer::singleShot(duration_end_msec, this, SLOT(EndAnimationProcess()));
}
