#include <abstract_sliding_widget_set.h>

#include <QVariant>
#include <QWidget>

#include <QDebug>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_widget_set_open)
    : QObject(parent),
      animation_group_(new QParallelAnimationGroup(this)),
      is_widget_set_open_(is_widget_set_open) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {
  if (close_geometry_vector_.size() == open_geometry_vector_.size()) {
    for (size_t i = 0; i < close_geometry_vector_.size(); ++i) {
      delete close_geometry_vector_.at(i);
      delete open_geometry_vector_.at(i);
    }
  } else {
    for (size_t i = 0; i < close_geometry_vector_.size(); ++i) {
      delete close_geometry_vector_.at(i);
    }
    for (size_t i = 0; i < open_geometry_vector_.size(); ++i) {
      delete open_geometry_vector_.at(i);
    }
  }
}

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

void AbstractSlidingWidgetSet::PerformAnimation() {
  UpdateWidgetSet();
  if (!is_widget_set_open_) {
    for (size_t i = 0; i < animation_vector_.size(); ++i) {
      animation_vector_.at(i)->setStartValue(*(close_geometry_vector_.at(i)));
      animation_vector_.at(i)->setEndValue(*(open_geometry_vector_.at(i)));
    }
    animation_group_->start();
    for (auto &elem : widget_vector_) {
      elem->show();
    }
  }
}

QVector<QWidget *> *AbstractSlidingWidgetSet::GetWidgetVector() {
  return &widget_vector_;
}

QVector<QPropertyAnimation *> *AbstractSlidingWidgetSet::GetAnimationVector() {
  return &animation_vector_;
}

QVector<QRect *> *AbstractSlidingWidgetSet::GetOpenGeometryVector() {
  return &open_geometry_vector_;
}

QVector<QRect *> *AbstractSlidingWidgetSet::GetCloseGeometryVector() {
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

  open_geometry_vector_.push_back(new QRect());
  close_geometry_vector_.push_back(new QRect());

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
