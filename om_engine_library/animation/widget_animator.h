#ifndef WIDGET_ANIMATOR_H
#define WIDGET_ANIMATOR_H

#include <QObject>
#include <QPair>
#include <QRect>

#include <om_utility.h>

class QPropertyAnimation;
class QWidget;
class QEasingCurve;

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
 public slots:
  void Close(const QRect& widget_geometry);
  void Open(const QRect& widget_geometry);

 signals:
  void AnimationComplete();

 protected slots:
  void StartAnimationProcess();
  void EndAnimationProcess();

 private:
  QPropertyAnimation* animation_ = nullptr;
  om_utility::WidgetAnimationType widget_animation_type_;
  QPair<QRect, QRect> animation_geometry_;
  unsigned int animation_duration_msec_ = 0;
  unsigned int animation_direction_ = 0;
};
}

#endif  // WIDGET_ANIMATOR_H
