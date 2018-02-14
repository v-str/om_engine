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
  typedef QVector<QPair<QVariant, QVariant>> ReverseGeometryVector;
  typedef QVector<QPair<QVariant, QVariant>> DirectGeometryVector;

  AbstractSlidingWidgetSet(QWidget* parent = nullptr,
                           bool is_widget_set_open = false);
  virtual ~AbstractSlidingWidgetSet();

  void Add(QWidget* widget);
  void SetAnimationDuration(unsigned int duration_msec);

  void UpdateWidgetSet();

  bool IsSetOpen() const;

 signals:
  void Open();
  void Close();

 public slots:
  void PerformAnimation();

 private slots:
  void OpenAnimationSet();
  void CloseAnimationSet();

 protected:
  virtual void SetAnimationGeometries() = 0;

  AnimationSet* GetAnimationSet();

 private:
  void CloseAsNeeded(QWidget* widget);
  void ComposeAnimationPair(QWidget* widget);
  QPropertyAnimation* GetDefaultAnimation(QWidget* widget);

  QParallelAnimationGroup* animation_group_ = nullptr;
  AnimationSet animation_set_;
  ReverseGeometryVector reverse_geometry_vector_;
  DirectGeometryVector direct_geometry_vector_;

  bool is_widget_set_open_;

  static const unsigned int kDefaultAnimationDurationMSec = 500;
};
}

#endif  // ABSTRACT_SLIDING_WIDGET_SET_H
