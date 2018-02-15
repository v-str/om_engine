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

LinearAnimationGroup::~LinearAnimationGroup() {}

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
  if (!is_animation_running_) {
    is_animation_running_ = true;
    UpdateWidgetSet();
    if (!is_widget_set_open_) {
      for (size_t i = 0; i < widgets_.size(); ++i) {
        animations_[i]->setStartValue(geometries_.at(i).second);
        animations_[i]->setEndValue(geometries_.at(i).first);
      }
      animation_group_->start();

      for (auto &widget : widgets_) {
        widget->show();
      }

      is_widget_set_open_ = true;

    } else {
      for (size_t i = 0; i < widgets_.size(); ++i) {
        animations_[i]->setStartValue(geometries_.at(i).first);
        animations_[i]->setEndValue(geometries_.at(i).second);
      }
      animation_group_->start();

      is_widget_set_open_ = false;
      is_need_to_close_ = true;
    }
  }
}

void LinearAnimationGroup::CloseAfterAnimation() {
  if (is_need_to_close_) {
    for (size_t i = 0; i < widgets_.size(); ++i) {
      widgets_[i]->close();
      widgets_[i]->setGeometry(geometries_[i].first);
    }
  }
  is_need_to_close_ = false;
  is_animation_running_ = false;
}

QVector<QWidget *> *LinearAnimationGroup::GetWidgets() { return &widgets_; }

QVector<QPair<QRect, QRect> > *LinearAnimationGroup::GetGeometryPair() {
  return &geometries_;
}

void LinearAnimationGroup::ResetGeometries() {
  for (size_t i = 0; i < widgets_.size(); ++i) {
    geometries_[i].first = widgets_.at(i)->geometry();
    geometries_[i].second = widgets_.at(i)->geometry();
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
      QPair<QRect, QRect>(widget->geometry(), widget->geometry()));
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
