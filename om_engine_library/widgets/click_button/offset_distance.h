#ifndef OFFSET_DISTANCE_H
#define OFFSET_DISTANCE_H

namespace om_widgets {

struct OffsetDistance {
  OffsetDistance(unsigned int offset_by_x = 0, unsigned int offset_by_y = 0);

  unsigned int GetOffSetDistanceX() const;
  unsigned int GetOffSetDistanceY() const;

 private:
  unsigned int offset_by_x_;
  unsigned int offset_by_y_;
};
}

#endif  // OFFSET_DISTANCE_H
