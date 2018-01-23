#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include <memory>

class WidgetAnimator;

namespace om_widgets {

class BaseWidget {
 public:
 private:
  std::unique_ptr<WidgetAnimator> animator_;
};
}

#endif  // BASE_WIDGET_H
