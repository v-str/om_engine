﻿#ifndef SHIFTER_H
#define SHIFTER_H

#include <QRect>

#include <geometry_modifier.h>
#include <geometry_utility.h>

namespace scaling {

class Shifter : public GeometryModifier {
 public:
  Shifter();
  ~Shifter();

  void ComputeModification(const QRect& initial_position) override;
  QRect GetModifiedRect() const override;

 private:
  QRect shifted_rect_;
};
}

#endif  // SHIFTER_H
