﻿#ifndef STATE_ANIMATOR_H
#define STATE_ANIMATOR_H

#include <QEasingCurve>
#include <QObject>
#include <QPair>
#include <QRect>
#include <QWidget>

#include <animation_utility.h>

class QPropertyAnimation;
class QWidget;

namespace om_animation {

class StateAnimator : public QObject {
  Q_OBJECT
 public:
  StateAnimator(QWidget* widget = nullptr, bool is_widget_open = true);
  ~StateAnimator();

  void SetAnimation(const QEasingCurve& curve = QEasingCurve::OutCirc,
                    unsigned int animation_duration_msec = 500,
                    unsigned int open_to = Side::kUp,
                    unsigned int close_in_to = Side::kDown);

  void SetCurrentGeometry(const QRect& widget_geometry);

  bool IsWidgetOpen() const;

 public slots:
  void Close();
  void Open();

 signals:
  void OpenAnimationComplete();
  void CloseAnimationComplete();
  void AnimationIncomplete();

 private slots:
  void StartAnimationProcess();
  void EndAnimationProcess();

 private:
  StateAnimator() = delete;
  StateAnimator(const StateAnimator&) = delete;
  StateAnimator(StateAnimator&&) = delete;
  StateAnimator& operator=(const StateAnimator&) = delete;
  StateAnimator& operator=(StateAnimator&&) = delete;

  void RunAnimation(WidgetAnimationType type, unsigned int animation_direction,
                    unsigned int duration_start_msec,
                    unsigned int duration_end_msec);

  void ChangeWidgetState();

  QPropertyAnimation* animation_ = nullptr;
  QWidget* control_widget_ = nullptr;

  QPair<QRect, QRect> animation_geometry_;
  QRect widget_geometry_;

  unsigned int animation_duration_msec_ = 0;
  unsigned int direction_open_to_ = 0;
  unsigned int direction_close_in_to_ = 0;
  bool is_widget_open_;
};
}

#endif  // STATE_ANIMATOR_H
