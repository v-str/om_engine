#include <abstract_sliding_widget_set.h>

#include <QVariant>
#include <QWidget>

#include <QDebug>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_widget_set_open)
    : QObject(parent),
      direct_animation_group_(new QParallelAnimationGroup(this)),
      is_widget_set_open_(is_widget_set_open) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}

void AbstractSlidingWidgetSet::Add(QWidget *widget) {
  CloseAsNeeded(widget);
  ComposeAnimationPair(widget);
  SetDirectAnimation();
}

void AbstractSlidingWidgetSet::SetAnimationDuration(
    unsigned int duration_msec) {
  for (auto &pair : direct_animation_set_) {
    pair.second->setDuration(duration_msec);
  }
}

void AbstractSlidingWidgetSet::UpdateWidgetSet() { SetDirectAnimation(); }

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_widget_set_open_; }

void AbstractSlidingWidgetSet::PerformAnimation() {}

void AbstractSlidingWidgetSet::OpenAnimationSet() {}

void AbstractSlidingWidgetSet::CloseAnimationSet() {}

AbstractSlidingWidgetSet::AnimationSet *
AbstractSlidingWidgetSet::GetDirectAnimationSet() {
  return &direct_animation_set_;
}

void AbstractSlidingWidgetSet::SetDirectAnimation() {}

void AbstractSlidingWidgetSet::CloseAsNeeded(QWidget *widget) {
  if (!is_widget_set_open_) {
    widget->close();
  }
}

void AbstractSlidingWidgetSet::ComposeAnimationPair(QWidget *widget) {
  QPropertyAnimation *direct_widget_animation = GetDefaultAnimation(widget);
  QPropertyAnimation *reverse_widget_animation = GetDefaultAnimation(widget);

  direct_animation_set_.push_back(
      QPair<QWidget *, QPropertyAnimation *>(widget, direct_widget_animation));
  direct_animation_group_->addAnimation(direct_widget_animation);
}

QPropertyAnimation *AbstractSlidingWidgetSet::GetDefaultAnimation(
    QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}
