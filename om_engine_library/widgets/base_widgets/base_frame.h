#ifndef BASE_FRAME_H
#define BASE_FRAME_H

#include <memory>

class WidgetAnimator;

namespace om_widgets {

class BaseFrame {
 public:
 private:
  std::unique_ptr<WidgetAnimator> animator_;
};
}

#endif  // BASE_FRAME_H
