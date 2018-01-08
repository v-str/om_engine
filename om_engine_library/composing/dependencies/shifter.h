﻿#ifndef SHIFTER_H
#define SHIFTER_H

#include <QPoint>

#include <geometry_modifier.h>

namespace om_composing {

class Shifter : virtual public GeometryModifier {
 public:
  void ComputeModification(const QRect& initial_position) override;
  QRect GetModifiedRect() const override;

 private:
  QRect shifted_rect_;
};
}

#endif  // SHIFTER_H
