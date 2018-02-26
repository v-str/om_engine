#include <v_linear_animation_group.h>

using namespace om_animation;
VLinearAnimationGroup::VLinearAnimationGroup(
    QWidget *parent, bool is_set_open,
    VLinearAnimationGroup::SlideDirection slide_direction,
    unsigned int distance_btw_widgets_px)
    : LinearAnimationGroup(parent, is_set_open),
      slide_direction_(slide_direction),
      distance_btw_widgets_px_(distance_btw_widgets_px) {}

VLinearAnimationGroup::~VLinearAnimationGroup() {}

void VLinearAnimationGroup::ComposeAnimation() {
  MakeCopy();

  if (slide_direction_ == kFromUpToDown) {
    CalculateFromUpToDown();
  }

  if (slide_direction_ == kFromDownToUp) {
    CalculateFromDownToUp();
  }

  ReassignGeometry();
}

void VLinearAnimationGroup::MakeCopy() {
  opening_geometry_.clear();
  closing_geometry_.clear();

  for (size_t i = 0; i < GetWidgets()->size(); ++i) {
    opening_geometry_.push_back(GetGeometryPair()->at(i).first);
    closing_geometry_.push_back(GetGeometryPair()->at(i).second);
  }
}

void VLinearAnimationGroup::CalculateFromUpToDown() {
  int initial_y_pos = opening_geometry_.at(0).y();
  int vectors_size = opening_geometry_.size();

  for (size_t i = 1; i < vectors_size; ++i) {
    initial_y_pos +=
        opening_geometry_.at(i - 1).height() + distance_btw_widgets_px_;

    opening_geometry_[i].setY(initial_y_pos);
  }

  initial_y_pos = opening_geometry_.at(0).y();

  for (size_t i = 0; i < vectors_size; ++i) {
    closing_geometry_[i].setY(initial_y_pos);
    closing_geometry_[i].setHeight(0);
  }
}

void VLinearAnimationGroup::CalculateFromDownToUp() {
  int initial_y_pos =
      opening_geometry_.last().y() + opening_geometry_.last().height();
  int vectors_size = opening_geometry_.size();

  for (size_t i = vectors_size - 1; i > -1; --i) {
    if (i == vectors_size - 1) {
      initial_y_pos -= opening_geometry_.at(i).height();
      opening_geometry_[i].setY(initial_y_pos);
    } else {
      initial_y_pos -=
          opening_geometry_.at(i).height() - distance_btw_widgets_px_;
      opening_geometry_[i].setY(initial_y_pos);
    }
  }

  initial_y_pos =
      opening_geometry_.last().y() + opening_geometry_.last().height();

  for (size_t i = 0; i < vectors_size; ++i) {
    closing_geometry_[i].setY(initial_y_pos);
    closing_geometry_[i].setHeight(0);
  }
}

void VLinearAnimationGroup::ReassignGeometry() {
  GetGeometryPair()->clear();
  for (size_t i = 0; i < opening_geometry_.size(); ++i) {
    GetGeometryPair()->push_back(
        QPair<QRect, QRect>(opening_geometry_.at(i), closing_geometry_.at(i)));
  }
}
