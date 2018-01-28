#include <geometry_modifier.h>

using namespace scaling;

void GeometryModifier::SetDeltaSize(const DeltaSize &delta_size) {
  delta_size_ = delta_size;
}

void GeometryModifier::SetDeltaSize(DeltaSize &&delta_size) {
  delta_size_ = std::move(delta_size);
}

void GeometryModifier::SetAxesRatio(const AxesRatio &axes_ratio) {
  axes_ratio_ = axes_ratio;
}

void GeometryModifier::ModifyTo(unsigned int modified_side) {
  modified_side_ = modified_side;
}
