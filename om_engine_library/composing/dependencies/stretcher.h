#ifndef STRETCHER_H
#define STRETCHER_H

#include <geometry_modifier.h>

namespace om_composing {

class Stretcher : public GeometryModifier {
 public:
  void ComputeModification(const QRect &initial_position) override;

  QRect GetStretchedRect() const;

 private:
  QRect stretched_rect_;
};
}

#endif  // STRETCHER_H
