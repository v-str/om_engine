#ifndef ABSTRACT_SLIDING_LIST_H
#define ABSTRACT_SLIDING_LIST_H

#include <QEasingCurve>
#include <QList>
#include <QObject>
#include <QRect>

#include <animation_utility.h>

class QWidget;

namespace om_animation {

class AbstractSlidingList : public QObject {
  Q_OBJECT
 public:
  AbstractSlidingList(QWidget* parent = nullptr);

  AbstractSlidingList(
      const QRect& guide_button_geometry, QWidget* parent = nullptr,
      GuideButtonPosition guide_button_position = kInTheBeginning);

  virtual ~AbstractSlidingList() = 0;

  void PushBackWidget(QWidget* widget);
  void PushFrontWidget(QWidget* widget);
  void InsertWidget(int index, QWidget* widget);
  void PopBackWidget();
  void PopFrontWidget();

  void SetGuideButtonGeometry(const QRect& guide_button_geometry);
  void SetSlidingDuration(unsigned int sliding_duration_msec);
  void SetSlidingCurve(QEasingCurve sliding_curve);

  // virtual methods, REMOVE IT AFTER COMPLETION
  virtual void SetSlidingDirection(unsigned int slide_direction) = 0;

  // end of virtual methods

  int SlidingBoxLength() const;

 private:
  AbstractSlidingList(const AbstractSlidingList& sliding_box) = delete;
  AbstractSlidingList(AbstractSlidingList&& sliding_box) = delete;
  AbstractSlidingList& operator=(const AbstractSlidingList& sliding_box) =
      delete;
  AbstractSlidingList& operator=(AbstractSlidingList&& sliding_box) = delete;

  GuideButtonPosition guide_button_position_;
  QRect guide_button_geometry_;
  QList<QWidget*> widget_list_;

  QEasingCurve sliding_curve_;

  unsigned int sliding_duration_msec_ = 0;
};
}

#endif  // ABSTRACT_SLIDING_LIST_H
