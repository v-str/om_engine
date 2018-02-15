#ifndef H_LINEAR_ANIMATION_GROUP_H
#define H_LINEAR_ANIMATION_GROUP_H

#include <memory>

#include <linear_animation_group.h>

class QWidget;

namespace om_animation {

class HLinearAnimationGroup : public LinearAnimationGroup {
 public:
  enum SlideDirection { kFromLeftToRight, kFromRightToLeft };

  HLinearAnimationGroup(QWidget* parent = nullptr, bool is_set_open = false,
                        SlideDirection slide_direction = kFromLeftToRight,
                        unsigned int distance_btw_widgets_px = 5);
  ~HLinearAnimationGroup();

 protected:
  void ComposeAnimation() override;

 private:
  SlideDirection slide_direction_;
  unsigned int distance_btw_widgets_px_;
};
}

#endif  // H_LINEAR_ANIMATION_GROUP_H
