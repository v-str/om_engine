#ifndef STRETCHER_H
#define STRETCHER_H

#include <geometry_modifier.h>

namespace geometry_modification {

class Stretcher : public GeometryModifier {
 public:
  void ComputeModification(const QRect &initial_position) override;
  QRect GetModifiedRect() const override;

 private:
  QRect stretched_rect_;
};
}

#endif  // STRETCHER_H
