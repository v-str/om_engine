#ifndef SHIFTER_H
#define SHIFTER_H

#include <QPoint>

#include <geometry_modifier.h>

namespace om_composing {

class Shifter : public GeometryModifier {
 public:
  void ComputeModification(const QRect& initial_position) override;
  QPoint GetShiftPoint() const;

 private:
  QPoint shift_point_;
};
}

#endif  // SHIFTER_H
