#ifndef WIDGET_ANIMATOR_H
#define WIDGET_ANIMATOR_H

#include <QObject>

class QPropertyAnimation;
class QWidget;
class QEasingCurve;
class QRect;

namespace om_animation {
class WidgetAnimator : public QObject {
  Q_OBJECT
 public:
  explicit WidgetAnimator(QWidget* widget = nullptr);
  ~WidgetAnimator();

  void SetAnimation(unsigned int animation_duration_msec,
                    const QEasingCurve& curve,
                    unsigned int animation_direction = 4);

 private:
};
}

#endif  // WIDGET_ANIMATOR_H
