#include <linear_animation_group.h>

#include <QVariant>
#include <QWidget>

#include <QDebug>

using namespace om_animation;

LinearAnimationGroup::LinearAnimationGroup(QWidget *parent,
                                           bool is_widget_set_open)
    : QObject(parent),
      is_widget_set_open_(is_widget_set_open),
      animation_group_(new QParallelAnimationGroup(this)) {
  connect(animation_group_, SIGNAL(finished()), SLOT(CloseAfterAnimation()));
}

LinearAnimationGroup::~LinearAnimationGroup() {
  if (!geometries_.isEmpty()) {
    for (auto &geometry_pair : geometries_) {
      delete geometry_pair;
    }
  }
}

void LinearAnimationGroup::Add(QWidget *widget) {
  CloseAsNeeded(widget);
  AddDependencies(widget);
}

void LinearAnimationGroup::SetAnimationProperties(
    unsigned int duration_msec, QEasingCurve animation_curve) {
  for (auto &animation : animations_) {
    animation->setDuration(duration_msec);
    animation->setEasingCurve(animation_curve);
  }
}

void LinearAnimationGroup::UpdateWidgetSet() {
  ResetGeometries();
  ComposeAnimation();
}

bool LinearAnimationGroup::IsSetOpen() const { return is_widget_set_open_; }

void LinearAnimationGroup::PerformAnimation() {
  UpdateWidgetSet();
  if (!is_widget_set_open_) {
  } else {
  }
}

void LinearAnimationGroup::CloseAfterAnimation() {
  // close

  // restore correct geometry
  // widget_->setGeometry(geometry_);
  is_need_to_close_ = false;
}

void LinearAnimationGroup::ResetGeometries() {
  for (size_t i = 0; i < widgets_.size(); ++i) {
    geometries_.at(i)->first = widgets_.at(i)->geometry();
    geometries_.at(i)->second = widgets_.at(i)->geometry();
  }
}

void LinearAnimationGroup::ComposeAnimation() {}

void LinearAnimationGroup::CloseAsNeeded(QWidget *widget) {
  if (!is_widget_set_open_) {
    widget->close();
  }
}

void LinearAnimationGroup::AddDependencies(QWidget *widget) {
  widgets_.push_back(widget);
  geometries_.push_back(
      new QPair<QRect, QRect>(widget->geometry(), widget->geometry()));
  QPropertyAnimation *animation = GetDefaultAnimation(widget);
  animations_.push_back(animation);
  animation_group_->addAnimation(animation);
}

QPropertyAnimation *LinearAnimationGroup::GetDefaultAnimation(QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}
