#ifndef OM_BUTTON_H
#define OM_BUTTON_H

#include <QPushButton>

#include <om_utility.h>

namespace OmUtility {
class OmButton : public QPushButton {
  Q_OBJECT
 public:
  explicit OmButton(QWidget* parent = nullptr);
  OmButton(const QString& button_text, QWidget* parent = nullptr);
  ~OmButton();

  void SetOffsetSide(const OmUtility::Side& side);
  void SetOffsetDistance(const OmUtility::OffsetDistance& offset_distance);

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  OmUtility::Side offset_side_;
  OmUtility::OffsetDistance offset_distance_;
};
}

#endif  // OM_BUTTON_H
