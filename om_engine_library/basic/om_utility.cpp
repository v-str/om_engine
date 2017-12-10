#include <om_utility.h>

OmEngine::OffsetDistance::OffsetDistance(unsigned int offset_by_x,
                                         unsigned int offset_by_y)
    : offset_by_x_(offset_by_x), offset_by_y_(offset_by_y) {}

unsigned int OmEngine::OffsetDistance::OffSetDistanceX() const {
  return offset_by_x_;
}

unsigned int OmEngine::OffsetDistance::OffSetDistanceY() const {
  return offset_by_y_;
}
