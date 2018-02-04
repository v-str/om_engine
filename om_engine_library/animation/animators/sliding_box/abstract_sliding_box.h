#ifndef ABSTRACT_SLIDING_BOX_H
#define ABSTRACT_SLIDING_BOX_H

#include <QObject>

class QWidget;

namespace om_animation {

class AbstractSlidingBox : public QObject {
  Q_OBJECT
 public:
  AbstractSlidingBox(QWidget* widget = nullptr);

 private:
};
}

#endif  // ABSTRACT_SLIDING_BOX_H
