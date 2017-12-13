#ifndef OM_UTILITY_H
#define OM_UTILITY_H

namespace om_utiliy {
enum Side { kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

struct OffsetDistance {
  OffsetDistance(unsigned int offset_by_x = 0, unsigned int offset_by_y = 0);

  unsigned int OffSetDistanceX() const;
  unsigned int OffSetDistanceY() const;

 private:
  unsigned int offset_by_x_;
  unsigned int offset_by_y_;
};
}

#endif  // OM_UTILITY_H
