#ifndef H_SLIDING_WIDGET_SET_H
#define H_SLIDING_WIDGET_SET_H

#include <abstract_sliding_widget_set.h>

class QWidget;

namespace om_animaiton {

class HSlidingWidgetSet : public AbstractSlidingWidgetSet {
 public:
  HSlidingWidgetSet(QWidget* parent = nullptr);
  ~HSlidingWidgetSet();

 protected:
  void SetStartAnimationPosition() override;
  void SetEndAnimationPosition() override;
};
}

#endif  // H_SLIDING_WIDGET_SET_H
