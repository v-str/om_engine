#ifndef OM_UTILITY_H
#define OM_UTILITY_H

namespace OmEngine {
enum Side { kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

struct OffsetDistance {
  OffsetDistance(unsigned int offset_by_x, unsigned int offset_by_y);
};
}

#endif  // OM_UTILITY_H
