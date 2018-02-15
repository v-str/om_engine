#include <linear_animation_group.h>

#include <QVariant>
#include <QWidget>

#include <QDebug>

using namespace om_animation;

LinearAnimationGroup::LinearAnimationGroup(QWidget *parent,
                                           bool is_widget_set_open)
    : QObject(parent), is_widget_set_open_(is_widget_set_open) {}

LinearAnimationGroup::~LinearAnimationGroup() {}

void LinearAnimationGroup::Add(QWidget *widget) {
  CloseAsNeeded(widget);

  widget_ = widget;

  animation_ = new QPropertyAnimation(widget, "geometry", this);
  animation_->setEasingCurve(QEasingCurve::OutCirc);
  animation_->setDuration(kDefaultAnimationDurationMSec);

  connect(animation_, SIGNAL(finished()), SLOT(CloseAfterAnimation()));
}

void LinearAnimationGroup::SetAnimationProperties(
    unsigned int duration_msec, QEasingCurve animation_curve) {
  animation_->setDuration(duration_msec);
  animation_->setEasingCurve(animation_curve);
}

void LinearAnimationGroup::UpdateWidgetSet() {
  geometry_ = widget_->geometry();
  ComposeAnimation();
}

bool LinearAnimationGroup::IsSetOpen() const { return is_widget_set_open_; }

void LinearAnimationGroup::PerformAnimation() {
  UpdateWidgetSet();
  if (!is_widget_set_open_) {
    animation_->setStartValue(CloseGeometry());
    animation_->setEndValue(OpenGeometry());
    animation_->start();
    widget_->show();
    is_widget_set_open_ = true;
  } else {
    animation_->setStartValue(OpenGeometry());
    animation_->setEndValue(CloseGeometry());
    animation_->start();
    is_need_to_close_ = true;
    is_widget_set_open_ = false;
  }
}

void LinearAnimationGroup::CloseAfterAnimation() {
  if (is_need_to_close_) {
    widget_->close();
  }
  // restore correct geometry
  widget_->setGeometry(geometry_);
  is_need_to_close_ = false;
}

void LinearAnimationGroup::ComposeAnimation() {}

void LinearAnimationGroup::CloseAsNeeded(QWidget *widget) {
  if (!is_widget_set_open_) {
    widget->close();
  }
}

QPropertyAnimation *LinearAnimationGroup::GetDefaultAnimation(QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}

QRect LinearAnimationGroup::OpenGeometry() { return geometry_; }

QRect LinearAnimationGroup::CloseGeometry() {
  QRect temp_rect = geometry_;
  temp_rect.setWidth(0);
  return temp_rect;
}
