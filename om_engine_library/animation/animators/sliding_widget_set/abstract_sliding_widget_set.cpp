#include <abstract_sliding_widget_set.h>

#include <QWidget>

using namespace om_animaiton;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_set_open)
    : QObject(parent),
      animation_group_(new QParallelAnimationGroup(this)),
      is_set_open_(is_set_open) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}

bool AbstractSlidingWidgetSet::Add(QWidget *widget) {
  CloseAsNeeded(widget);
  QPropertyAnimation *widget_animation = GetDefaultAnimation(widget);
  animation_set_.push_back(
      QPair<QWidget *, QPropertyAnimation *>(widget, widget_animation));

  SetStartAnimationPosition();
  SetEndAnimationPosition();

  animation_group_->addAnimation(widget_animation);
}

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_set_open_; }

void AbstractSlidingWidgetSet::Open() {
  animation_group_->start();

  for (auto &pair : animation_set_) {
    pair.first->show();
  }

  emit AnimationComplete();
}

QPropertyAnimation *AbstractSlidingWidgetSet::GetDefaultAnimation(
    QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}

QVector<QPair<QWidget *, QPropertyAnimation *> >
    *AbstractSlidingWidgetSet::GetAnimationSet() {
  return &animation_set_;
}

void AbstractSlidingWidgetSet::SetEndAnimationPosition() {}

void AbstractSlidingWidgetSet::SetStartAnimationPosition() {}

void AbstractSlidingWidgetSet::CloseAsNeeded(QWidget *widget) {
  if (!is_set_open_) {
    widget->close();
  }
}
