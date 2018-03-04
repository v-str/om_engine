#ifndef GEOMETRY_MODIFIER_H
#define GEOMETRY_MODIFIER_H

#include <QRect>

#include <delta_size.h>
#include <axes_ratio.h>

namespace scaling {

class GeometryModifier {
 public:
  GeometryModifier() = default;
  virtual ~GeometryModifier() = default;

  virtual void ComputeModification(const QRect& initial_position) = 0;
  virtual QRect GetModifiedRect() const = 0;

  virtual void SetDeltaSize(const DeltaSize& delta_size);
  virtual void SetDeltaSize(DeltaSize&& delta_size);

  virtual void SetAxesRatio(const AxesRatio& axes_ratio);
  virtual void ModifyTo(unsigned int modified_side);

 protected:
  AxesRatio axes_ratio_;
  DeltaSize delta_size_;

  unsigned int modified_side_ = 0;
};
}

#endif  // GEOMETRY_MODIFIER_H
