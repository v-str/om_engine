#include <abstract_sliding_list.h>

#include <QWidget>

using namespace om_animation;

AbstractSlidingList::AbstractSlidingList(QWidget *parent) : QObject(parent) {}

AbstractSlidingList::AbstractSlidingList(
    const QRect &guide_button_geometry, QWidget *parent,
    GuideButtonPosition guide_button_position)
    : guide_button_geometry_(guide_button_geometry),
      QObject(parent),
      guide_button_position_(guide_button_position) {}

AbstractSlidingList::~AbstractSlidingList() {}

void AbstractSlidingList::PushBackWidget(QWidget *widget) {
  widget_list_.push_back(widget);
}

void AbstractSlidingList::PushFrontWidget(QWidget *widget) {
  widget_list_.push_front(widget);
}

void AbstractSlidingList::InsertWidget(int index, QWidget *widget) {
  widget_list_.insert(index, widget);
}

void AbstractSlidingList::PopBackWidget() {
  if (!widget_list_.isEmpty()) {
    widget_list_.pop_back();
  }
}

void AbstractSlidingList::PopFrontWidget() {
  if (!widget_list_.isEmpty()) {
    widget_list_.pop_front();
  }
}

int AbstractSlidingList::SlidingBoxLength() const {
  return widget_list_.length();
}
