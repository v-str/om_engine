﻿#ifndef H_SLIDING_WIDGET_SET_H
#define H_SLIDING_WIDGET_SET_H

#include <abstract_sliding_widget_set.h>

class QWidget;

namespace om_animaiton {

class HSlidingWidgetSet : public AbstractSlidingWidgetSet {
 public:
  enum SlideDirection { kFromLeftToRight, kFromRightToLeft };

  HSlidingWidgetSet(QWidget* parent = nullptr, bool is_set_open = false,
                    SlideDirection slide_direction = kFromLeftToRight);
  ~HSlidingWidgetSet();

 protected:
  void SetStartAnimationPosition() override;
  void SetEndAnimationPosition() override;

 private:
  SlideDirection slide_direction_;
};
}

#endif  // H_SLIDING_WIDGET_SET_H
