#ifndef OM_TIME_LABEL_H
#define OM_TIME_LABEL_H

#include <abstract_clock.h>

namespace om_widgets {
class OmTimeLabel : public AbstractClock {
  Q_OBJECT
 public:
  OmTimeLabel(QWidget* parent = nullptr);
  ~OmTimeLabel();

  void Update() override;

 private:
};
}
#endif  // OM_TIME_LABEL_H
