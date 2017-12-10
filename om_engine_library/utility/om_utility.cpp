#include <om_utility.h>

OmUtility::OffsetDistance::OffsetDistance(unsigned int offset_by_x,
                                          unsigned int offset_by_y)
    : offset_by_x_(offset_by_x), offset_by_y_(offset_by_y) {}

unsigned int OmUtility::OffsetDistance::OffSetDistanceX() const {
  return offset_by_x_;
}

unsigned int OmUtility::OffsetDistance::OffSetDistanceY() const {
  return offset_by_y_;
}
