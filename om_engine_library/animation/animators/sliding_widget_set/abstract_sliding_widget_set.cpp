#include <abstract_sliding_widget_set.h>

#include <QVariant>
#include <QWidget>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_widget_set_open)
    : QObject(parent),
      direct_animation_group_(new QParallelAnimationGroup(this)),
      reverse_animation_group_(new QParallelAnimationGroup(this)),
      is_widget_set_open_(is_widget_set_open) {
  connect(this, SIGNAL(Open()), SLOT(OpenAnimationSet()));
  connect(this, SIGNAL(Close()), SLOT(CloseAnimationSet()));
  connect(reverse_animation_group_, SIGNAL(finished()),
          SLOT(CloseWidgetsForcibly()));
}

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
  for (auto &pair : reverse_animation_set_) {
    pair.second->setDuration(duration_msec);
  }
}

void AbstractSlidingWidgetSet::UpdateWidgetSet() {
  SetDirectAnimation();
  SetReverseAnimation();
}

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_widget_set_open_; }

void AbstractSlidingWidgetSet::PerformAnimation() {
  UpdateWidgetSet();
  if (!is_widget_set_open_) {
    emit Open();
  } else {
    emit Close();
  }
}

void AbstractSlidingWidgetSet::OpenAnimationSet() {
  direct_animation_group_->start();

  for (auto &pair : direct_animation_set_) {
    pair.first->show();
  }

  is_widget_set_open_ = true;
}

void AbstractSlidingWidgetSet::CloseAnimationSet() {
  reverse_animation_group_->start();

  is_widget_set_open_ = false;
  is_forcibly_closed_ = true;
}

AbstractSlidingWidgetSet::AnimationSet *
AbstractSlidingWidgetSet::GetDirectAnimationSet() {
  return &direct_animation_set_;
}

AbstractSlidingWidgetSet::AnimationSet *
AbstractSlidingWidgetSet::GetReverseAnimationSet() {
  return &reverse_animation_set_;
}

void AbstractSlidingWidgetSet::SetReverseAnimation() {}

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

  reverse_animation_set_.push_back(
      QPair<QWidget *, QPropertyAnimation *>(widget, reverse_widget_animation));
  reverse_animation_group_->addAnimation(reverse_widget_animation);
}

QPropertyAnimation *AbstractSlidingWidgetSet::GetDefaultAnimation(
    QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}

void AbstractSlidingWidgetSet::CloseWidgetsForcibly() {
  if (is_forcibly_closed_) {
    for (auto &pair : reverse_animation_set_) {
      pair.first->close();
    }
  }
  is_forcibly_closed_ = false;
}
