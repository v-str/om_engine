#ifndef OM_BUTTON_H
#define OM_BUTTON_H

#include <QPushButton>

#include <om_utility.h>

namespace om_widgets {

using namespace om_utility;

class OmButton : public QPushButton {
  Q_OBJECT
 public:
  explicit OmButton(QWidget* parent = nullptr);
  OmButton(const QString& button_text, QWidget* parent = nullptr);
  ~OmButton();

  void SetOffsetSide(unsigned int offset_side);
  void SetOffsetDistance(const om_utility::OffsetDistance& offset_distance);

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  unsigned int offset_side_;
  OffsetDistance offset_distance_;
};
}

#endif  // OM_BUTTON_H
