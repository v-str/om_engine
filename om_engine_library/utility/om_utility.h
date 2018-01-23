#ifndef OM_UTILITY_H
#define OM_UTILITY_H

class QLabel;
class QRect;

namespace om_utility {
//enum Side { kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

//enum WidgetAnimationType { kOpen, kClose };

enum TransformationType { kShifting, kStretching, kScaling };

struct TimeDateChanger {
  static void ChangeTime(QLabel* time_label);
  static void ChangeDate(QLabel* date_label);
};
}

#endif  // OM_UTILITY_H
