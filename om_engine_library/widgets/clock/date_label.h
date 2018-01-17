#ifndef DATE_LABEL_H
#define DATE_LABEL_H

#include <abstract_clock.h>

namespace om_widgets {

class OmDateLabel : public AbstractClock {
  Q_OBJECT
 public:
  OmDateLabel(QWidget* parent = nullptr);
  ~OmDateLabel();

  void Update() override;

 private:
};
}
#endif  // DATE_LABEL_H
