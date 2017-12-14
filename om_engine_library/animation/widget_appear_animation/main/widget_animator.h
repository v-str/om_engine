﻿#ifndef WIDGET_ANIMATOR_H
#define WIDGET_ANIMATOR_H

#include <QEasingCurve>
#include <QObject>
#include <QPair>
#include <QPropertyAnimation>
#include <QRect>
#include <QWidget>

#include <om_utility.h>

class QPropertyAnimation;
class QWidget;

using namespace om_utility;

namespace om_animation {
class WidgetAnimator : public QObject {
  Q_OBJECT
 public:
  explicit WidgetAnimator(QWidget* widget = nullptr);
  ~WidgetAnimator();

  void SetAnimation(const QEasingCurve& curve = QEasingCurve::OutCirc,
                    unsigned int animation_duration_msec = 500,
                    unsigned int animation_direction = om_utility::Side::kDown);

  void SetCurrentGeometry(const QRect& widget_geometry);

 public slots:
  void Close();
  void Open();

 signals:
  void AnimationComplete();

 protected slots:
  void StartAnimationProcess();
  void EndAnimationProcess();

 private:
  void RunAnimation(unsigned int duration_start_msec,
                    unsigned int duration_end_msec);

  QPropertyAnimation* animation_ = nullptr;
  QPair<QRect, QRect> animation_geometry_;
  unsigned int animation_duration_msec_ = 0;
  unsigned int animation_direction_ = 0;

  QRect widget_geometry_;
};
}

#endif  // WIDGET_ANIMATOR_H