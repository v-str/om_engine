#include <abstract_sliding_widget_set.h>

#include <QWidget>

using namespace om_animaiton;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent,
                                                   bool is_set_open)
    : QObject(parent),
      animation_group_(new QParallelAnimationGroup(this)),
      is_set_open_(is_set_open) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}

bool AbstractSlidingWidgetSet::Add(QWidget *widget) { CloseAsNeeded(widget); }

bool AbstractSlidingWidgetSet::IsSetOpen() const { return is_set_open_; }

void AbstractSlidingWidgetSet::CloseAsNeeded(QWidget *widget) {
  if (!is_set_open_) {
    widget->close();
  }
}
