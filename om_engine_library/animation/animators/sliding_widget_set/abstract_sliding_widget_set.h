#ifndef ABSTRACT_SLIDING_WIDGET_SET_H
#define ABSTRACT_SLIDING_WIDGET_SET_H

#include <QEasingCurve>
#include <QObject>
#include <QPair>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QRect>
#include <QVector>

class QWidget;

namespace om_animation {

class AbstractSlidingWidgetSet : public QObject {
  Q_OBJECT
 public:
  AbstractSlidingWidgetSet(QWidget* parent = nullptr,
                           bool is_widget_set_open = false);
  virtual ~AbstractSlidingWidgetSet();

  void Add(QWidget* widget);
  void SetAnimationProperties(
      unsigned int duration_msec = 500,
      QEasingCurve animation_curve = QEasingCurve::OutCirc);

  void UpdateWidgetSet();

  bool IsSetOpen() const;

 public slots:
  void PerformAnimation();

 private slots:
  void CloseAfterAnimation();

 protected:
  virtual void ComposeAnimation() = 0;

 private:
  void CloseAsNeeded(QWidget* widget);
  QPropertyAnimation* GetDefaultAnimation(QWidget* widget);

  QRect OpenGeometry();
  QRect CloseGeometry();

  QPropertyAnimation* animation_ = nullptr;

  QRect geometry_;

  QWidget* widget_ = nullptr;

  bool is_widget_set_open_ = false;
  bool is_need_to_close_ = false;

  static const unsigned int kDefaultAnimationDurationMSec = 500;
};
}

#endif  // ABSTRACT_SLIDING_WIDGET_SET_H
