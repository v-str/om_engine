#ifndef ABSTRACT_SLIDING_BOX_H
#define ABSTRACT_SLIDING_BOX_H

#include <QList>
#include <QObject>
#include <QRect>

#include <animation_utility.h>

class QWidget;

namespace om_animation {

class AbstractSlidingBox : public QObject {
  Q_OBJECT
 public:
  AbstractSlidingBox(QWidget* parent = nullptr);

  AbstractSlidingBox(
      const QRect& guide_button_geometry, QWidget* parent = nullptr,
      GuideButtonPosition guide_button_position = kInTheBeginning);

  virtual ~AbstractSlidingBox() = 0;

 protected:
 private:
  AbstractSlidingBox(const AbstractSlidingBox& sliding_box) = delete;
  AbstractSlidingBox(AbstractSlidingBox&& sliding_box) = delete;
  AbstractSlidingBox& operator=(const AbstractSlidingBox& sliding_box) = delete;
  AbstractSlidingBox& operator=(AbstractSlidingBox&& sliding_box) = delete;

  GuideButtonPosition guide_button_position_;
  QRect guide_button_geometry_;
  QList<QWidget*> widget_list_;
};
}

#endif  // ABSTRACT_SLIDING_BOX_H
