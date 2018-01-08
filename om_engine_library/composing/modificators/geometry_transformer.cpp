#include <geometry_transformer.h>

#include <QRect>
#include <QWidget>

using namespace om_composing;

GeometryTransformer::GeometryTransformer(
    const ModificationFactor &modification_factor, unsigned int side_to_modify,
    TransformationType type) {}

GeometryTransformer::GeometryTransformer(
    const ModificationFactor &modification_shift_factor,
    const ModificationFactor &modification_stretch_factor, Side shift_to,
    Side stretch_to) {}
