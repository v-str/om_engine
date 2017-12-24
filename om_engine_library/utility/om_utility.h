#ifndef OM_UTILITY_H
#define OM_UTILITY_H

class QLabel;

namespace om_utility {
enum Side { kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

enum WidgetAnimationType { kOpen, kClose };

struct OffsetDistance {
  OffsetDistance(unsigned int offset_by_x = 0, unsigned int offset_by_y = 0);

  unsigned int OffSetDistanceX() const;
  unsigned int OffSetDistanceY() const;

 private:
  unsigned int offset_by_x_;
  unsigned int offset_by_y_;
};

struct TimeDateChanger {
  static void ChangeTime(QLabel* time_label);
  static void ChangeDate(QLabel* date_label);
};
}

#endif  // OM_UTILITY_H
