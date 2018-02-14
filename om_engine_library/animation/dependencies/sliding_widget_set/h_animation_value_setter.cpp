#include <h_animation_value_setter.h>

#include <QRect>

using namespace om_animation;

HAnimationValueSetter::HAnimationValueSetter(
    AnimationValueSetter::AnimationSet *direct_animation_set,
    unsigned int slide_direction, unsigned int distance_between_widgets_px)
    : AnimationValueSetter(direct_animation_set, slide_direction,
                           distance_between_widgets_px) {}

HAnimationValueSetter::~HAnimationValueSetter() {}

void HAnimationValueSetter::DetermineStartXPosition() {
  if (slide_direction_ == kFromLeftToRight) {
    unsigned int x_of_first_widget = direct_animation_set_->first().first->x();
    start_x_pos_ = x_of_first_widget;
  }
  if (slide_direction_ == kFromRightToLeft) {
    unsigned int x_of_last_widget = direct_animation_set_->last().first->x();
    unsigned int width_of_last_widget =
        direct_animation_set_->last().first->width();

    start_x_pos_ = x_of_last_widget + width_of_last_widget;
  }
}

void HAnimationValueSetter::SetDirectStartValue() {
  if (!direct_animation_set_->isEmpty()) {
    DetermineStartXPosition();

    for (auto &pair : *direct_animation_set_) {
      pair.second->setStartValue(
          QRect(start_x_pos_, pair.first->y(), 0, pair.first->height()));
    }
  }
}

void HAnimationValueSetter::SetDirectEndValue() {
  if (!direct_animation_set_->isEmpty()) {
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

  for (int index = 0; index < direct_animation_set_->size(); ++index) {
    if (count == 0) {
      AssignNewEndAnimationValue(index, start_x_pos_);
    } else {
      unsigned int x_position = start_x_pos_;
      for (int inner_index = 1; inner_index <= count; ++inner_index) {
        x_position += direct_animation_set_->at(inner_index).first->width() +
                      distance_between_widgets_px_;
      }
      AssignNewEndAnimationValue(index, x_position);
      x_position = start_x_pos_;
    }
    ++count;
  }
}

void HAnimationValueSetter::CalculateRightToLeftEndValue() {
  int set_size = direct_animation_set_->size() - 1;
  for (int index = set_size; index > -1; --index) {
    if (index == set_size) {
      start_x_pos_ -= direct_animation_set_->at(index).first->width();
      AssignNewEndAnimationValue(index, start_x_pos_);
    } else {
      start_x_pos_ -= direct_animation_set_->at(index).first->width() +
                      distance_between_widgets_px_;
      AssignNewEndAnimationValue(index, start_x_pos_);
    }
  }
}

void HAnimationValueSetter::AssignNewEndAnimationValue(
    int index, unsigned int x_position) {
  direct_animation_set_->at(index).second->setEndValue(
      QRect(x_position, direct_animation_set_->at(index).first->y(),
            direct_animation_set_->at(index).first->width(),
            direct_animation_set_->at(index).first->height()));
}
