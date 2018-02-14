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
  AbstractSlidingWidgetSet(QWidget* parent = nullptr,
                           bool is_widget_set_open = false);
  virtual ~AbstractSlidingWidgetSet();

  void Add(QWidget* widget);
  void SetAnimationDuration(unsigned int duration_msec);

  void UpdateWidgetSet();

  bool IsSetOpen() const;

 public slots:
  void PerformAnimation();

 protected:
  virtual void ComposeAnimation() = 0;

  QVector<QWidget*>* GetWidgetVector();
  QVector<QPropertyAnimation*>* GetAnimationVector();
  QVector<QRect>* GetOpenGeometryVector();
  QVector<QRect>* GetCloseGeometryVector();

 private:
  void CloseAsNeeded(QWidget* widget);
  void AddToVectors(QWidget* widget);
  QPropertyAnimation* GetDefaultAnimation(QWidget* widget);

  QVector<QWidget*> widget_vector_;
  QVector<QPropertyAnimation*> animation_vector_;
  QVector<QRect> open_geometry_vector_;
  QVector<QRect> close_geometry_vector_;

  QParallelAnimationGroup* animation_group_ = nullptr;

  bool is_widget_set_open_ = false;

  static const unsigned int kDefaultAnimationDurationMSec = 500;
};
}

#endif  // ABSTRACT_SLIDING_WIDGET_SET_H
