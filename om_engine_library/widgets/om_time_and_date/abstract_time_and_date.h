#ifndef ABSTRACT_TIME_AND_DATE_H
#define ABSTRACT_TIME_AND_DATE_H

#include <QLabel>
#include <QTimer>

namespace om_widgets {

class AbstractTimeAndDate : public QLabel {
 public:
  AbstractTimeAndDate(QLabel* parent = nullptr) : QLabel(parent) {}
  ~AbstractTimeAndDate() {}

  virtual void Update() = 0;

 protected:
  unsigned int TimerTick() { return kTimerTick; }

 private:
  QTimer* timer_ = nullptr;

  static const unsigned int kTimerTick = 1000;
};
}

#endif  // ABSTRACT_TIME_AND_DATE_H
