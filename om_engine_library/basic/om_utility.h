#ifndef OM_UTILITY_H
#define OM_UTILITY_H

namespace OmEngine {
enum Side { kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

struct OffsetDistance {
  OffsetDistance(unsigned int offset_by_x, unsigned int offset_by_y);

  unsigned int OffSetDistanceX() const;
  unsigned int OffSetDistanceY() const;

 private:
  unsigned int offset_by_x_ = 0;
  unsigned int offset_by_y_ = 0;
};
}

#endif  // OM_UTILITY_H
