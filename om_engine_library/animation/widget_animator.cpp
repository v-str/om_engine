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
  animation_->setStartValue(animation_geometry_.first);
  animation_->setEndValue(animation_geometry_.second);
  QTimer::singleShot(0, this, SLOT(StartAnimationProcess()));
  QTimer::singleShot(animation_duration_msec_, this,
                     SLOT(EndAnimationProcess()));
}

void om_animation::WidgetAnimator::Open() {
  animation_geometry_ = AnimationGeometrySetter::GetAnimationForOpening(
      animation_direction_, widget_geometry_);
  animation_->setStartValue(animation_geometry_.first);
  animation_->setEndValue(animation_geometry_.second);
  QTimer::singleShot(animation_duration_msec_, this,
                     SLOT(StartAnimationProcess()));
  QTimer::singleShot(animation_duration_msec_, this,
                     SLOT(EndAnimationProcess()));
}

void om_animation::WidgetAnimator::StartAnimationProcess() {
  animation_->start();
}

void om_animation::WidgetAnimator::EndAnimationProcess() {
  emit AnimationComplete();
}
