#include <geometry_modifier.h>

using namespace om_composing;

void GeometryModifier::SetModificationFactor(
    const ModificationFactor &modification_factor) {
  modification_factor_ = modification_factor;
}

void GeometryModifier::SetDeltaSize(const DeltaSize &delta_size) {
  delta_size_ = delta_size;
}

void GeometryModifier::ModifyTo(unsigned int modified_side) {
  modified_side_ = modified_side;
}
