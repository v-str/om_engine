#ifndef ABSTRACT_SLIDING_WIDGET_SET_H
#define ABSTRACT_SLIDING_WIDGET_SET_H

#include <QObject>

class QWidget;

namespace om_animaiton {

class AbstractSlidingWidgetSet : public QObject {
  Q_OBJECT
 public:
  AbstractSlidingWidgetSet(QWidget* parent = nullptr);
  ~AbstractSlidingWidgetSet();

 private:
};
}

#endif  // ABSTRACT_SLIDING_WIDGET_SET_H
