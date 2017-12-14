#include <widget_animator.h>

#include <QTimer>

#include <animation_geometry_setter.h>

using namespace om_animation;

WidgetAnimator::WidgetAnimator(QWidget* widget)
    : QObject(), animation_(new QPropertyAnimation(widget, "geometry", this)) {}

WidgetAnimator::~WidgetAnimator() {}

void WidgetAnimator::SetAnimation(const QEasingCurve& curve,
                                  unsigned int animation_duration_msec,
                                  unsigned int open_to,
                                  unsigned int close_in_to) {
  animation_->setEasingCurve(curve);
  animation_->setDuration(animation_duration_msec);
  direction_open_to_ = open_to;
  direction_close_in_to_ = close_in_to;
}

void WidgetAnimator::SetCurrentGeometry(const QRect& widget_geometry) {
  widget_geometry_ = widget_geometry;
}

void WidgetAnimator::Close() {
  animation_geometry_ = AnimationGeometrySetter::GetGeometryFor(
      WidgetAnimationType::kClose, direction_close_in_to_, widget_geometry_);
  RunAnimation(0, animation_duration_msec_);
}

void WidgetAnimator::Open() {
  animation_geometry_ = AnimationGeometrySetter::GetGeometryFor(
      WidgetAnimationType::kOpen, direction_open_to_, widget_geometry_);
  RunAnimation(animation_duration_msec_, animation_duration_msec_);
}

void WidgetAnimator::StartAnimationProcess() { animation_->start(); }

void WidgetAnimator::EndAnimationProcess() { emit AnimationComplete(); }

void WidgetAnimator::RunAnimation(unsigned int duration_start_msec,
                                  unsigned int duration_end_msec) {
  animation_->setStartValue(animation_geometry_.first);
  animation_->setEndValue(animation_geometry_.second);
  QTimer::singleShot(duration_start_msec, this, SLOT(StartAnimationProcess()));
  QTimer::singleShot(duration_end_msec, this, SLOT(EndAnimationProcess()));
}
