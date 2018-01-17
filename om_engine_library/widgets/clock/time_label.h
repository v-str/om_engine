#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <abstract_clock.h>

namespace om_widgets {
class TimeLabel : public AbstractClock {
  Q_OBJECT
 public:
  TimeLabel(QWidget* parent = nullptr);

  void Update() override;

 private:
};
}
#endif  // TIME_LABEL_H
