#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <abstract_clock.h>

namespace om_widgets {
class TimeLabel : public AbstractClock {
  Q_OBJECT
 public:
  TimeLabel(QWidget* parent = nullptr);
  ~TimeLabel();

  void Update() override;
};
}
#endif  // TIME_LABEL_H
