#include <abstract_sliding_box.h>

#include <QWidget>

using namespace om_animation;

AbstractSlidingBox::AbstractSlidingBox(QWidget *parent) : QObject(parent) {}

AbstractSlidingBox::AbstractSlidingBox(
    const QRect &guide_button_geometry, QWidget *parent,
    GuideButtonPosition guide_button_position)
    : guide_button_geometry_(guide_button_geometry),
      QObject(parent),
      guide_button_position_(guide_button_position) {}

AbstractSlidingBox::~AbstractSlidingBox() {}

void AbstractSlidingBox::PushBackWidget(QWidget *widget) {
  widget_list_.push_back(widget);
}

void AbstractSlidingBox::PushFrontWidget(QWidget *widget) {
  widget_list_.push_front(widget);
}

void AbstractSlidingBox::InsertWidget(int index, QWidget *widget) {
  widget_list_.insert(index, widget);
}

void AbstractSlidingBox::PopBackWidget() {
  if (!widget_list_.isEmpty()) {
    widget_list_.pop_back();
  }
}

void AbstractSlidingBox::PopFrontWidget() {
  if (!widget_list_.isEmpty()) {
    widget_list_.pop_front();
  }
}

int AbstractSlidingBox::SlidingBoxLength() const {
  return widget_list_.length();
}
