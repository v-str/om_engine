#ifndef GEOMETRY_MODIFIER_FACTORY_H
#define GEOMETRY_MODIFIER_FACTORY_H

#include <geometry_modifier.h>
#include <om_utility.h>

class GeometryModifierFactory {
 public:
  geometry_modification::GeometryModifier* Create(
      om_utility::TransformationType& type);
};

#endif  // GEOMETRY_MODIFIER_FACTORY_H
