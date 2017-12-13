#ifndef WIDGET_ANIMATOR_H
#define WIDGET_ANIMATOR_H

#include <QObject>

#include <om_utility.h>

class QPropertyAnimation;
class QWidget;
class QEasingCurve;
class QRect;

using namespace om_utility;

namespace om_animation {
class WidgetAnimator : public QObject {
  Q_OBJECT
 public:
  explicit WidgetAnimator(QWidget* widget = nullptr);
  ~WidgetAnimator();

  void SetAnimation(om_utility::WidgetAnimationType widget_animation_type,
                    const QEasingCurve& curve,
                    unsigned int animation_duration_msec = 500,
                    unsigned int animation_direction = om_utility::Side::kDown);

 private:
  QPropertyAnimation* property_animation_ = nullptr;
  om_utility::WidgetAnimationType widget_animation_type_;
  unsigned int animation_duration_msec_ = 0;
  unsigned int animation_direction_ = 0;
};
}

#endif  // WIDGET_ANIMATOR_H
