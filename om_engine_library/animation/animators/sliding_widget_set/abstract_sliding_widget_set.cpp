﻿#include <abstract_sliding_widget_set.h>

#include <QVariant>
#include <QWidget>

#include <QDebug>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_widget_set_open)
    : QObject(parent),
      animation_group_(new QParallelAnimationGroup(this)),
      is_widget_set_open_(is_widget_set_open) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}

void AbstractSlidingWidgetSet::Add(QWidget *widget) {
  CloseAsNeeded(widget);
  AddToVectors(widget);
  ComposeAnimation();
}

void AbstractSlidingWidgetSet::SetAnimationDuration(
    unsigned int duration_msec) {
  for (auto &animation : animation_vector_) {
    animation->setDuration(duration_msec);
  }
}

void AbstractSlidingWidgetSet::UpdateWidgetSet() { ComposeAnimation(); }

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_widget_set_open_; }

void AbstractSlidingWidgetSet::PerformAnimation() {}

QVector<QWidget *> *AbstractSlidingWidgetSet::GetWidgetVector() {
  return &widget_vector_;
}

QVector<QPropertyAnimation *> *AbstractSlidingWidgetSet::GetAnimationVector() {
  return &animation_vector_;
}

QVector<QRect> *AbstractSlidingWidgetSet::GetOpenGeometryVector() {
  return &open_geometry_vector_;
}

QVector<QRect> *AbstractSlidingWidgetSet::GetCloseGeometryVector() {
  return &close_geometry_vector_;
}

void AbstractSlidingWidgetSet::ComposeAnimation() {}

void AbstractSlidingWidgetSet::CloseAsNeeded(QWidget *widget) {
  if (!is_widget_set_open_) {
    widget->close();
  }
}

void AbstractSlidingWidgetSet::AddToVectors(QWidget *widget) {
  widget_vector_.push_back(widget);

  QPropertyAnimation *animation = GetDefaultAnimation(widget);
  animation_vector_.push_back(animation);

  animation_group_->addAnimation(animation);
}

QPropertyAnimation *AbstractSlidingWidgetSet::GetDefaultAnimation(
    QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}
