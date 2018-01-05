#ifndef GEOMETRY_COMPOSER_H
#define GEOMETRY_COMPOSER_H

#include <geometry_modifier.h>
#include <om_utility.h>

namespace om_composing {

class GeometryComposer {
 public:


 private:
  GeometryModifier* shifter_ = nullptr;
  GeometryModifier* stretcher_ = nullptr;
};
}

#endif  // GEOMETRY_COMPOSER_H
