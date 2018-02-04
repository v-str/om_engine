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
