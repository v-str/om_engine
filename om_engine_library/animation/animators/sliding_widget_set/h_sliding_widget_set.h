#ifndef H_SLIDING_WIDGET_SET_H
#define H_SLIDING_WIDGET_SET_H

#include <memory>

#include <abstract_sliding_widget_set.h>

class QWidget;

namespace om_animation {

class HSlidingWidgetSet : public AbstractSlidingWidgetSet {
 public:
  enum SlideDirection { kFromLeftToRight, kFromRightToLeft };

  HSlidingWidgetSet(QWidget* parent = nullptr, bool is_set_open = false,
                    SlideDirection slide_direction = kFromLeftToRight,
                    unsigned int distance_btw_widgets_px = 5);
  ~HSlidingWidgetSet();

 protected:
  void ComposeAnimation() override;

 private:
  SlideDirection slide_direction_;
  unsigned int distance_btw_widgets_px_;
};
}

#endif  // H_SLIDING_WIDGET_SET_H
