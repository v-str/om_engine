#include <offset_distance.h>

using namespace om_widgets;

OffsetDistance::OffsetDistance(unsigned int offset_by_x,
                               unsigned int offset_by_y)
    : offset_by_x_(offset_by_x), offset_by_y_(offset_by_y) {}

unsigned int OffsetDistance::GetOffSetDistanceX() const { return offset_by_x_; }

unsigned int OffsetDistance::GetOffSetDistanceY() const { return offset_by_y_; }
