#ifndef ABSTRACT_SLIDING_WIDGET_SET_H
#define ABSTRACT_SLIDING_WIDGET_SET_H

#include <QEasingCurve>
#include <QObject>
#include <QPair>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QVector>

class QWidget;

namespace om_animation {

class AbstractSlidingWidgetSet : public QObject {
  Q_OBJECT
 public:
  typedef QVector<QPair<QWidget*, QPropertyAnimation*>> AnimationSet;

  AbstractSlidingWidgetSet(QWidget* parent = nullptr, bool is_set_open = false);
  virtual ~AbstractSlidingWidgetSet();

  void Add(QWidget* widget);
  void SetAnimationDuration(unsigned int duration_msec);

  void UpdateWidgetSet();

  bool IsSetOpen() const;

 signals:
  void AnimationComplete();

 public slots:
  void Open();

 protected:
  virtual void AppointAnimationParameters() = 0;

  AnimationSet* GetAnimationSet();

 private:
  void CloseAsNeeded(QWidget* widget);
  void ComposeAnimationPair(QWidget* widget);
  QPropertyAnimation* GetDefaultAnimation(QWidget* widget);

  QParallelAnimationGroup* animation_group_ = nullptr;
  AnimationSet animation_set_;

  bool is_set_open_;

  static const unsigned int kDefaultAnimationDurationMSec = 500;
};
}

#endif  // ABSTRACT_SLIDING_WIDGET_SET_H
