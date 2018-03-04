#ifndef ABSTRACT_CLOCK_H
#define ABSTRACT_CLOCK_H

#include <QLabel>

class QTimer;

namespace om_widgets {

class AbstractClock : public QLabel {
  Q_OBJECT
 public:
  AbstractClock(QWidget* parent = nullptr);
  ~AbstractClock();
  virtual void Update() = 0;

 protected slots:
  void RunUpdate();

 protected:
  unsigned int TimerTick();
  void InitializeTimer(QLabel* label);

 private:
  QTimer* timer_ = nullptr;

  static constexpr unsigned int kOneSecondTick = 1000;
};
}

#endif  // ABSTRACT_CLOCK_H
