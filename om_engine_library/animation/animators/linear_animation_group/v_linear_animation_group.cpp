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

void VLinearAnimationGroup::CalculateFromUpToDown() {}

void VLinearAnimationGroup::CalculateFromDownToUp() {}

void VLinearAnimationGroup::ReassignGeometry() {
  GetGeometryPair()->clear();
  for (size_t i = 0; i < opening_geometry_.size(); ++i) {
    GetGeometryPair()->push_back(
        QPair<QRect, QRect>(opening_geometry_.at(i), closing_geometry_.at(i)));
  }
}
