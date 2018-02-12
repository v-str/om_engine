#include <h_animation_value_setter.h>

#include <QRect>

using namespace om_animation;

HAnimationValueSetter::HAnimationValueSetter(
    AnimationValueSetter::AnimationSet *animation_set,
    unsigned int slide_direction, unsigned int distance_between_widgets_px)
    : AnimationValueSetter(animation_set, slide_direction,
                           distance_between_widgets_px) {}

HAnimationValueSetter::~HAnimationValueSetter() {}

void HAnimationValueSetter::DetermineStartXPosition() {
  if (slide_direction_ == kFromLeftToRight) {
    unsigned int x_of_first_widget = animation_set_->first().first->x();
    start_x_pos_ = x_of_first_widget;
  }
  if (slide_direction_ == kFromRightToLeft) {
    unsigned int x_of_last_widget = animation_set_->last().first->x();
    unsigned int width_of_last_widget = animation_set_->last().first->width();

    start_x_pos_ = x_of_last_widget + width_of_last_widget;
  }
}

void HAnimationValueSetter::SetStartValue() {
  if (!animation_set_->isEmpty()) {
    DetermineStartXPosition();

    for (auto &pair : *animation_set_) {
      pair.second->setStartValue(
          QRect(start_x_pos_, pair.first->y(), 0, pair.first->height()));
    }
  }
}

void HAnimationValueSetter::SetEndValue() {
  if (!animation_set_->isEmpty()) {
    if (slide_direction_ == kFromLeftToRight) {
      CalculateLeftToRightEndValue();
    }
    if (slide_direction_ == kFromRightToLeft) {
      CalculateRightToLeftEndValue();
    }
  }
}

void HAnimationValueSetter::CalculateLeftToRightEndValue() {
  unsigned int count = 0;

  for (auto i = 0; i < animation_set_->size(); ++i) {
    if (count == 0) {
      animation_set_->at(i).second->setEndValue(
          QRect(start_x_pos_, animation_set_->at(i).first->y(),
                animation_set_->at(i).first->width(),
                animation_set_->at(i).first->height()));
    } else {
      unsigned int x_position = start_x_pos_;
      for (auto i = 1; i <= count; ++i) {
        x_position +=
            animation_set_->at(i).first->width() + distance_between_widgets_px_;
      }
      animation_set_->at(i).second->setEndValue(
          QRect(x_position, animation_set_->at(i).first->y(),
                animation_set_->at(i).first->width(),
                animation_set_->at(i).first->height()));
      x_position = start_x_pos_;
    }
    ++count;
  }
}

void HAnimationValueSetter::CalculateRightToLeftEndValue() {
  auto set_size = animation_set_->size() - 1;
  for (auto i = set_size; i > -1; --i) {
    if (i == set_size) {
      start_x_pos_ -= animation_set_->at(i).first->width();
      animation_set_->at(i).second->setEndValue(
          QRect(start_x_pos_, animation_set_->at(i).first->y(),
                animation_set_->at(i).first->width(),
                animation_set_->at(i).first->height()));
    } else {
      start_x_pos_ -=
          animation_set_->at(i).first->width() + distance_between_widgets_px_;
      animation_set_->at(i).second->setEndValue(
          QRect(start_x_pos_, animation_set_->at(i).first->y(),
                animation_set_->at(i).first->width(),
                animation_set_->at(i).first->height()));
    }
  }
}
