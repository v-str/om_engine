#ifndef SLIDING_WIDGET_SET_H
#define SLIDING_WIDGET_SET_H

#include <QObject>
#include <QPair>
#include <QParallelAnimationGroup>
#include <QVector>

class QWidget;
class QPropertyAnimation;

namespace om_animation {

class SlidingWidgetSet : public QObject {
  Q_OBJECT
 public:
  SlidingWidgetSet(QWidget* parent = nullptr);
  ~SlidingWidgetSet();

  void SetAnimationDuration(unsigned int animation_duration_msec = 500);
  void Add(QWidget* widget);

  void SetStartXPos(unsigned int start_x_pos);

 signals:
  void Complete();

 public slots:
  void Open();

 private:
  void SetStartAnimationValue(QWidget* widget, QPropertyAnimation* animation);
  void SetEndAnimationValue(QWidget* widget, QPropertyAnimation* animation);

  QVector<QPair<QWidget*, QPropertyAnimation*>> animation_storage_;
  QParallelAnimationGroup animation_group_;

  unsigned int start_x_pos_ = 0;
};
}
#endif  // SLIDING_WIDGET_SET_H
