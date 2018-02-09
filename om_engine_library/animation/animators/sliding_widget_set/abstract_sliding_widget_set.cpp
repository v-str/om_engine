#include <abstract_sliding_widget_set.h>

#include <QWidget>

using namespace om_animaiton;

AbstractSlidingWidgetSet::AbstractSlidingWidgetSet(QWidget *parent)
    : QObject(parent), animation_group_(new QParallelAnimationGroup(this)) {}

AbstractSlidingWidgetSet::~AbstractSlidingWidgetSet() {}
