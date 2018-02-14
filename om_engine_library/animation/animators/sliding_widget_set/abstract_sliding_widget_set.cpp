#include <abstract_sliding_widget_set.h>

#include <QVariant>
#include <QWidget>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_widget_set_open)
    : QObject(parent),
      animation_group_(new QParallelAnimationGroup(this)),
      is_widget_set_open_(is_widget_set_open) {
  connect(animation_group_, SIGNAL(finished()),
          SLOT(InvertAnimationParameters()));
}

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

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_widget_set_open_; }

void AbstractSlidingWidgetSet::PerformAnimation() {
  animation_group_->start();
  if (!is_widget_set_open_) {
    for (auto &pair : animation_set_) {
      pair.first->show();
    }
    emit OpenAnimationComplete();
  }
  if (is_widget_set_open_) {
    emit CloseAnimationComplete();
  }
}

void AbstractSlidingWidgetSet::InvertAnimationParameters() {
  for (auto &pair : animation_set_) {
    QVariant start_value = pair.second->endValue();
    QVariant end_value = pair.second->startValue();

    pair.second->setStartValue(start_value);
    pair.second->setEndValue(end_value);
  }
  is_widget_set_open_ == false ? is_widget_set_open_ = true
                               : is_widget_set_open_ = false;
}

AbstractSlidingWidgetSet::AnimationSet *
AbstractSlidingWidgetSet::GetAnimationSet() {
  return &animation_set_;
}

void AbstractSlidingWidgetSet::AppointAnimationParameters() {}

void AbstractSlidingWidgetSet::CloseAsNeeded(QWidget *widget) {
  if (!is_widget_set_open_) {
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
