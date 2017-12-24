#ifndef OM_DATE_LABEL_H
#define OM_DATE_LABEL_H

#include <abstract_time_and_date.h>

namespace om_widgets {

class OmDateLabel : public AbstractTimeAndDate {
  Q_OBJECT
 public:
  OmDateLabel(QLabel* parent = nullptr);
  ~OmDateLabel();

  void Update() override;

 private:
};
}
#endif  // OM_DATE_LABEL_H
