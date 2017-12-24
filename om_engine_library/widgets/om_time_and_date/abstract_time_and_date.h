#ifndef ABSTRACT_TIME_AND_DATE_H
#define ABSTRACT_TIME_AND_DATE_H

namespace om_widgets {

class AbstractTimeAndDate {
 public:
  virtual void Update() = 0;

 protected:
  unsigned int TimerTick() { return kTimerTick; }

 private:
  static const unsigned int kTimerTick = 1000;
};
}

#endif  // ABSTRACT_TIME_AND_DATE_H
