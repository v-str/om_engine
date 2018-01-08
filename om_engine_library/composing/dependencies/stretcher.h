#ifndef STRETCHER_H
#define STRETCHER_H

#include <geometry_modifier.h>

namespace om_composing {

class Stretcher : virtual public GeometryModifier {
 public:
  void ComputeModification(const QRect &initial_position) override;
  QRect GetModifiedRect() const override;

 private:
  QRect stretched_rect_;
};
}

#endif  // STRETCHER_H
