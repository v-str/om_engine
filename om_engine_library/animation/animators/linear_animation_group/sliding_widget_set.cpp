#include <sliding_widget_set.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QWidget>

using namespace om_animation;

SlidingWidgetSet::SlidingWidgetSet(QWidget *parent)
    : QObject(parent), animation_group_(new QParallelAnimationGroup(this)) {
  SetAnimationDuration();
}

SlidingWidgetSet::~SlidingWidgetSet() {}

void SlidingWidgetSet::SetAnimationDuration(
    unsigned int animation_duration_msec) {
  for (auto &pair : animation_storage_) {
    pair.second->setDuration(animation_duration_msec);
  }
}

void SlidingWidgetSet::Add(QWidget *widget) {
  widget->close();

  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  SetStartAnimationValue(widget, animation);
  SetEndAnimationValue(widget, animation);

  animation_storage_.push_back(
      QPair<QWidget *, QPropertyAnimation *>(widget, animation));

  animation_group_.addAnimation(animation);
}

void SlidingWidgetSet::SetStartXPos(unsigned int start_x_pos) {
  start_x_pos_ = start_x_pos;

  for (auto &pair : animation_storage_) {
    SetStartAnimationValue(pair.first, pair.second);
    SetEndAnimationValue(pair.first, pair.second);
  }
}

void SlidingWidgetSet::Open() {
  animation_group_.start();

  for (auto &pair : animation_storage_) {
    pair.first->show();
  }

  emit Complete();
}

void SlidingWidgetSet::SetStartAnimationValue(QWidget *widget,
                                              QPropertyAnimation *animation) {
  animation->setStartValue(
      QRect(start_x_pos_, widget->y(), 0, widget->height()));
}

void SlidingWidgetSet::SetEndAnimationValue(QWidget *widget,
                                            QPropertyAnimation *animation) {
  animation->setEndValue(widget->geometry());
}
