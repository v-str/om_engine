﻿#include <widget_condition_animator.h>

#include <QPropertyAnimation>
#include <QTimer>

#include <animation_geometry_setter.h>

using namespace om_animation;

WidgetConditionAnimator::WidgetConditionAnimator(QWidget* widget, bool is_widget_open)
    : QObject(),
      animation_(new QPropertyAnimation(widget, "geometry", this)),
      is_widget_open_(is_widget_open) {
  if (!is_widget_open_) {
    widget->close();
  }
}

WidgetConditionAnimator::~WidgetConditionAnimator() {}

void WidgetConditionAnimator::SetAnimation(const QEasingCurve& curve,
                                  unsigned int animation_duration_msec,
                                  unsigned int open_to,
                                  unsigned int close_in_to) {
  animation_->setEasingCurve(curve);
  animation_->setDuration(animation_duration_msec);
  direction_open_to_ = open_to;
  direction_close_in_to_ = close_in_to;
}

void WidgetConditionAnimator::SetCurrentGeometry(const QRect& widget_geometry) {
  widget_geometry_ = widget_geometry;
}

bool WidgetConditionAnimator::IsWidgetOpen() const { return is_widget_open_; }

void WidgetConditionAnimator::Close() {
  if (is_widget_open_) {
    RunAnimation(kClose, direction_close_in_to_, 0, animation_duration_msec_);
  } else {
    emit AnimationIncomplete();
  }
}

void WidgetConditionAnimator::Open() {
  if (!is_widget_open_) {
    RunAnimation(kOpen, direction_open_to_, animation_duration_msec_,
                 animation_duration_msec_);
  } else {
    emit AnimationIncomplete();
  }
}

void WidgetConditionAnimator::StartAnimationProcess() { animation_->start(); }

void WidgetConditionAnimator::EndAnimationProcess() { emit AnimationComplete(); }

void WidgetConditionAnimator::RunAnimation(WidgetAnimationType type,
                                  unsigned int animation_direction,
                                  unsigned int duration_start_msec,
                                  unsigned int duration_end_msec) {
  animation_geometry_ = AnimationGeometrySetter::GetGeometryFor(
      widget_geometry_, type, animation_direction);
  animation_->setStartValue(animation_geometry_.first);
  animation_->setEndValue(animation_geometry_.second);
  QTimer::singleShot(duration_start_msec, this, SLOT(StartAnimationProcess()));
  QTimer::singleShot(duration_end_msec, this, SLOT(EndAnimationProcess()));
  ChangeWidgetState();
}

void WidgetConditionAnimator::ChangeWidgetState() {
  is_widget_open_ ? is_widget_open_ = false : is_widget_open_ = true;
}