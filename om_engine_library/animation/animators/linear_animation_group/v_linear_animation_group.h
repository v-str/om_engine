#ifndef V_LINEAR_ANIMATION_GROUP_H
#define V_LINEAR_ANIMATION_GROUP_H

#include <QRect>
#include <QVector>

#include <linear_animation_group.h>

class QWidget;

namespace om_animation {

class VLinearAnimationGroup : public LinearAnimationGroup {
 public:
  enum SlideDirection { kFromUpToDown, kFromDownToUp };

  VLinearAnimationGroup(QWidget* parent = nullptr, bool is_set_open = false,
                        SlideDirection slide_direction = kFromUpToDown,
                        unsigned int distance_btw_widgets_px = 5);
  ~VLinearAnimationGroup();

 protected:
  void ComposeAnimation() override;

 private:
  void MakeCopy();
  void CalculateFromUpToDown();
  void CalculateFromDownToUp();
  void ReassignGeometry();

  SlideDirection slide_direction_;
  unsigned int distance_btw_widgets_px_;

  QVector<QRect> opening_geometry_;
  QVector<QRect> closing_geometry_;
};
}

#endif  // V_LINEAR_ANIMATION_GROUP_H
