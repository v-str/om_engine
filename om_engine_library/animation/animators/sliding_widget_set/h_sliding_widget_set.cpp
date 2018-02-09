#include <h_sliding_widget_set.h>

#include <QRect>
#include <QWidget>

using namespace om_animation;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent, bool is_set_open,
                                     SlideDirection slide_direction)
    : AbstractSlidingWidgetSet(parent, is_set_open),
      slide_direction_(slide_direction) {}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::SetStartAnimationPosition() {
  DetermineStartXPosition();

  if (slide_direction_ == kFromLeftToRight) {
    for (auto &pair : *GetAnimationSet()) {
      pair.second->setStartValue(
          QRect(start_x_position_, pair.first->y(), 0, pair.first->height()));
    }
  }
}

void HSlidingWidgetSet::SetEndAnimationPosition() {
  if (slide_direction_ == kFromLeftToRight) {
    unsigned int count = 0;

    for (auto &pair : *GetAnimationSet()) {
      if (count == 0) {
        pair.second->setEndValue(QRect(start_x_position_, pair.first->y(),
                                       pair.first->width(),
                                       pair.first->height()));
      } else {
        unsigned int x_position = start_x_position_;
        for (auto it = GetAnimationSet()->begin();
             it < GetAnimationSet()->begin() + count; ++it) {
          x_position += it->first->width() + GetMargin();
        }
        pair.second->setEndValue(QRect(x_position, pair.first->y(),
                                       pair.first->width(),
                                       pair.first->height()));
        x_position = start_x_position_;
      }

      ++count;
    }
  }
}

void HSlidingWidgetSet::DetermineStartXPosition() {
  if (slide_direction_ == kFromLeftToRight) {
    unsigned int x_of_first_widget = GetAnimationSet()[0].first().first->x();
    start_x_position_ = x_of_first_widget;
  }
}
