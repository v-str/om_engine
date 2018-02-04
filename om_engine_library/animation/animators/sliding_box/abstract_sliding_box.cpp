#include <abstract_sliding_box.h>

#include <QWidget>

using namespace om_animation;

AbstractSlidingBox::AbstractSlidingBox(QWidget *widget,
                                       GuideButton button_state,
                                       GuideButtonPosition button_position)
    : QObject(widget),
      button_state_(button_state),
      button_position_(button_position) {}
