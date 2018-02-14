#include <abstract_sliding_widget_set.h>

#include <QVariant>
#include <QWidget>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_widget_set_open)
    : QObject(parent),
      animation_group_(new QParallelAnimationGroup(this)),
      is_widget_set_open_(is_widget_set_open) {
  connect(this, SIGNAL(Open()), SLOT(OpenAnimationSet()));
  connect(this, SIGNAL(Close()), SLOT(CloseAnimationSet()));
}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}

void AbstractSlidingWidgetSet::Add(QWidget *widget) {
  CloseAsNeeded(widget);
  ComposeAnimationPair(widget);
  SetAnimationGeometries();
}

void AbstractSlidingWidgetSet::SetAnimationDuration(
    unsigned int duration_msec) {
  for (auto &pair : animation_set_) {
    pair.second->setDuration(duration_msec);
  }
}

void AbstractSlidingWidgetSet::UpdateWidgetSet() {
  SetAnimationGeometries();
  // SetReverseAnimationGeometries();
}

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_widget_set_open_; }

void AbstractSlidingWidgetSet::PerformAnimation() {
  UpdateWidgetSet();
  if (!is_widget_set_open_) {
    emit Open();
  }
  if (is_widget_set_open_) {
    emit Close();
  }
}

void AbstractSlidingWidgetSet::OpenAnimationSet() {}

void AbstractSlidingWidgetSet::CloseAnimationSet() {}

AbstractSlidingWidgetSet::AnimationSet *
AbstractSlidingWidgetSet::GetAnimationSet() {
  return &animation_set_;
}

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
