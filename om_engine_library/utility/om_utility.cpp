﻿#include <om_utility.h>

om_utility::OffsetDistance::OffsetDistance(unsigned int offset_by_x,
                                           unsigned int offset_by_y)
    : offset_by_x_(offset_by_x), offset_by_y_(offset_by_y) {}

unsigned int om_utility::OffsetDistance::OffSetDistanceX() const {
  return offset_by_x_;
}

unsigned int om_utility::OffsetDistance::OffSetDistanceY() const {
  return offset_by_y_;
}
