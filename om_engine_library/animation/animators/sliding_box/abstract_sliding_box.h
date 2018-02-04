#ifndef ABSTRACT_SLIDING_BOX_H
#define ABSTRACT_SLIDING_BOX_H

#include <QList>
#include <QObject>

#include <animation_utility.h>

class QWidget;

namespace om_animation {

class AbstractSlidingBox : public QObject {
  Q_OBJECT
 public:
  AbstractSlidingBox(QWidget* widget = nullptr, GuideButton button_state = kOn,
                     GuideButtonPosition button_position = kInTheBeginning);

 protected:
  GuideButton button_state_;
  GuideButtonPosition button_position_;

  QList<QWidget*> widget_list_;
};
}

#endif  // ABSTRACT_SLIDING_BOX_H
