#ifndef OM_DATE_LABEL_H
#define OM_DATE_LABEL_H

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
#endif  // OM_DATE_LABEL_H
