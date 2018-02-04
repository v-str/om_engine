#ifndef ABSTRACT_SLIDING_BOX_H
#define ABSTRACT_SLIDING_BOX_H

#include <QList>
#include <QObject>

class QWidget;

namespace om_animation {

class AbstractSlidingBox : public QObject {
  Q_OBJECT
 public:
  AbstractSlidingBox(QWidget* widget = nullptr);

 protected:
  QList<QWidget*> widget_list_;
};
}

#endif  // ABSTRACT_SLIDING_BOX_H
