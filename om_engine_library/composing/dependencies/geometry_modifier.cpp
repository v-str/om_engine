#include <geometry_modifier.h>

using namespace om_composing;

void GeometryModifier::SetModificationConversion(
    const ConversionMaker &modification_converstion) {
  modification_converstion_ = modification_converstion;
}

void GeometryModifier::SetDeltaSize(const DeltaSize &delta_size) {
  delta_size_ = delta_size;
}

void GeometryModifier::ModifyTo(unsigned int modified_side) {
  modified_side_ = modified_side;
}
