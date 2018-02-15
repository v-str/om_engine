#include <abstract_sliding_widget_set.h>

#include <QVariant>
#include <QWidget>

#include <QDebug>

using namespace om_animation;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_widget_set_open)
    : QObject(parent), is_widget_set_open_(is_widget_set_open) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}

void AbstractSlidingWidgetSet::Add(QWidget *widget) {
  CloseAsNeeded(widget);

  widget_ = widget;

  geometry_ = widget->geometry();

  animation_ = new QPropertyAnimation(widget, "geometry", this);
  animation_->setEasingCurve(QEasingCurve::OutCirc);
  animation_->setDuration(kDefaultAnimationDurationMSec);

  connect(animation_, SIGNAL(finished()), SLOT(CloseAfterAnimation()));
}

void AbstractSlidingWidgetSet::SetAnimationProperties(
    unsigned int duration_msec, QEasingCurve animation_curve) {
  animation_->setDuration(duration_msec);
  animation_->setEasingCurve(animation_curve);
}

void AbstractSlidingWidgetSet::UpdateWidgetSet() {
  geometry_ = widget_->geometry();
}

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_widget_set_open_; }

void AbstractSlidingWidgetSet::PerformAnimation() {
  UpdateWidgetSet();
  if (!is_widget_set_open_) {
    animation_->setStartValue(CloseGeometry());
    animation_->setEndValue(OpenGeometry());
    animation_->start();
    widget_->show();
    is_widget_set_open_ = true;
  } else {
    qDebug() << "before w: " << widget_->width();
    animation_->setStartValue(OpenGeometry());
    animation_->setEndValue(CloseGeometry());
    animation_->start();
    is_need_to_close_ = true;
    is_widget_set_open_ = false;
  }
}

void AbstractSlidingWidgetSet::CloseAfterAnimation() {
  if (is_need_to_close_) {
    widget_->close();
  }
  qDebug() << "\n\t in startValue() w: "
           << animation_->startValue().toRect().width();
  qDebug() << "\t in endValue() w: " << animation_->endValue().toRect().width()
           << "\n";

  // restore correct geometry
  widget_->setGeometry(geometry_);

  qDebug() << "after w: " << widget_->width();
  is_need_to_close_ = false;
}

void AbstractSlidingWidgetSet::ComposeAnimation() {}

void AbstractSlidingWidgetSet::CloseAsNeeded(QWidget *widget) {
  if (!is_widget_set_open_) {
    widget->close();
  }
}

QPropertyAnimation *AbstractSlidingWidgetSet::GetDefaultAnimation(
    QWidget *widget) {
  QPropertyAnimation *animation =
      new QPropertyAnimation(widget, "geometry", this);

  animation->setDuration(kDefaultAnimationDurationMSec);
  animation->setEasingCurve(QEasingCurve::OutCirc);

  return animation;
}

QRect AbstractSlidingWidgetSet::OpenGeometry() { return geometry_; }

QRect AbstractSlidingWidgetSet::CloseGeometry() {
  QRect temp_rect = geometry_;
  temp_rect.setWidth(0);
  return temp_rect;
}
