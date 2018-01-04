#ifndef SHIFTER_H
#define SHIFTER_H

#include <QPoint>
#include <QRect>

#include <conversion_maker.h>
#include <delta_size.h>
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
