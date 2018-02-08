#ifndef SLIDING_WIDGET_SET_H
#define SLIDING_WIDGET_SET_H

#include <QObject>

class QWidget;

namespace om_animation {

class SlidingWidgetSet : public QObject {
  Q_OBJECT
 public:
  SlidingWidgetSet(QWidget* parent = nullptr);
  ~SlidingWidgetSet();

 private:
};
}
#endif  // SLIDING_WIDGET_SET_H
