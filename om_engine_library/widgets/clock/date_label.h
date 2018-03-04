#ifndef DATE_LABEL_H
#define DATE_LABEL_H

#include <abstract_clock.h>

namespace om_widgets {

class DateLabel : public AbstractClock {
  Q_OBJECT
 public:
  DateLabel(QWidget* parent = nullptr);
  ~DateLabel();

  void Update() override;
};
}

#endif  // DATE_LABEL_H
