#ifndef LINEAR_ANIMATION_GROUP_H
#define LINEAR_ANIMATION_GROUP_H

#include <QEasingCurve>
#include <QObject>
#include <QPair>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QRect>
#include <QVector>

class QWidget;

namespace om_animation {

class LinearAnimationGroup : public QObject {
  Q_OBJECT
 public:
  LinearAnimationGroup(QWidget* parent = nullptr,
                       bool is_widget_set_open = false);
  virtual ~LinearAnimationGroup();

  void Add(QWidget* widget);
  void SetAnimationProperties(unsigned int duration_msec,
                              QEasingCurve animation_curve);

  void UpdateWidgetSet();

  bool IsSetOpen() const;

 public slots:
  void PerformAnimation();

 private slots:
  void CloseAfterAnimation();

 protected:
  virtual void ComposeAnimation() = 0;

  QVector<QWidget*>* GetWidgets();
  QVector<QPair<QRect, QRect>>* GetGeometryPair();

 private:
  void ResetGeometries();
  void CloseAsNeeded(QWidget* widget);
  void AddDependencies(QWidget* widget);
  QPropertyAnimation* GetDefaultAnimation(QWidget* widget);
  void PerformOpenAnimation();
  void PerformCloseAnimation();

  QVector<QWidget*> widgets_;
  QVector<QPair<QRect, QRect>> geometries_;
  QVector<QPropertyAnimation*> animations_;

  QParallelAnimationGroup* animation_group_ = nullptr;

  bool is_widget_set_open_ = false;
  bool is_need_to_close_ = false;
  bool is_animation_running_ = false;

  static const unsigned int kDefaultAnimationDurationMSec = 500;
};
}

#endif  // LINEAR_ANIMATION_GROUP_H
