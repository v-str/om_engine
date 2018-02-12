﻿#include <abstract_sliding_widget_set.h>

#include <QWidget>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_set_open)
    : QObject(parent),
      animation_group_(new QParallelAnimationGroup(this)),
      is_set_open_(is_set_open) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}

void AbstractSlidingWidgetSet::Add(QWidget *widget) {
  CloseAsNeeded(widget);
  ComposeAnimationPair(widget);
  AppointAnimationParameters();
}

void AbstractSlidingWidgetSet::SetAnimationDuration(
    unsigned int duration_msec) {
  for (auto &pair : animation_set_) {
    pair.second->setDuration(duration_msec);
  }
}

void AbstractSlidingWidgetSet::UpdateWidgetSet() {
  AppointAnimationParameters();
}

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_set_open_; }

void AbstractSlidingWidgetSet::Open() {
  animation_group_->start();

  for (auto &pair : animation_set_) {
    pair.first->show();
  }

  emit OpenAnimationComplete();
}

void AbstractSlidingWidgetSet::Close() {
  animation_group_->start();

  for (auto &pair : animation_set_) {
    pair.first->close();
  }

  emit CloseAnimationComplete();
}

AbstractSlidingWidgetSet::AnimationSet *
AbstractSlidingWidgetSet::GetAnimationSet() {
  return &animation_set_;
}

void AbstractSlidingWidgetSet::AppointAnimationParameters() {}

void AbstractSlidingWidgetSet::CloseAsNeeded(QWidget *widget) {
  if (!is_set_open_) {
    widget->close();
  }
}

void AbstractSlidingWidgetSet::ComposeAnimationPair(QWidget *widget) {
  QPropertyAnimation *widget_animation = GetDefaultAnimation(widget);
  animation_set_.push_back(
      QPair<QWidget *, QPropertyAnimation *>(widget, widget_animation));
  animation_group_->addAnimation(widget_animation);
}

QPropertyAnimation *AbstractSlidingWidgetSet::GetDefaultAnimation(
    QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}
