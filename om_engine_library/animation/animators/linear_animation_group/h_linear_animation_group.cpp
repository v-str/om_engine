#include <h_linear_animation_group.h>

#include <QRect>
#include <QVariant>
#include <QWidget>

using namespace om_animation;

HLinearAnimationGroup::HLinearAnimationGroup(
    QWidget *parent, bool is_set_open, SlideDirection slide_direction,
    unsigned int distance_btw_widgets_px)
    : LinearAnimationGroup(parent, is_set_open),
      slide_direction_(slide_direction),
      distance_btw_widgets_px_(distance_btw_widgets_px) {}

HLinearAnimationGroup::~HLinearAnimationGroup() {}

void HLinearAnimationGroup::ComposeAnimation() {
  MakeCopy();

  if (slide_direction_ == kFromLeftToRight) {
    CalculateFromLeftToRight();
  }

  if (slide_direction_ == kFromRightToLeft) {
  }

  ReassignGeometry();
}

void HLinearAnimationGroup::MakeCopy() {
  opening_geometry_.clear();
  closing_geometry_.clear();

  for (size_t i = 0; i < GetWidgets()->size(); ++i) {
    opening_geometry_.push_back(GetGeometryPair()->at(i).first);
    closing_geometry_.push_back(GetGeometryPair()->at(i).second);
  }
}

void HLinearAnimationGroup::CalculateFromLeftToRight() {
  int initial_x_pos = opening_geometry_.at(0).x();
  int vectors_size = opening_geometry_.size();

  for (size_t i = 1; i < vectors_size; ++i) {
    initial_x_pos +=
        opening_geometry_.at(i - 1).width() + distance_btw_widgets_px_;

    opening_geometry_[i].setX(initial_x_pos);
  }

  initial_x_pos = opening_geometry_.at(0).x();

  for (size_t i = 0; i < vectors_size; ++i) {
    closing_geometry_[i].setX(initial_x_pos);
    closing_geometry_[i].setWidth(0);
  }
}

void HLinearAnimationGroup::ReassignGeometry() {
  GetGeometryPair()->clear();
  for (size_t i = 0; i < opening_geometry_.size(); ++i) {
    GetGeometryPair()->push_back(
        QPair<QRect, QRect>(opening_geometry_.at(i), closing_geometry_.at(i)));
  }
}
