#ifndef H_SLIDING_WIDGET_SET_H
#define H_SLIDING_WIDGET_SET_H

#include <memory>

#include <abstract_sliding_widget_set.h>

class QWidget;

namespace om_animation {

class HSlidingWidgetSet : public AbstractSlidingWidgetSet {
 public:
  enum SlideDirection { kFromLeftToRight, kFromRightToLeft };

  HSlidingWidgetSet(QWidget* parent = nullptr,
                    SlideDirection slide_direction = kFromLeftToRight,
                    unsigned int distance_between_widgets_px = 5,
                    bool is_set_open = false);
  ~HSlidingWidgetSet();

 protected:
  void ComposeAnimation() override;

 private:
};
}

#endif  // H_SLIDING_WIDGET_SET_H
