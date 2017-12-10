#ifndef OM_BUTTON_H
#define OM_BUTTON_H

#include <QPushButton>

#include <om_utility.h>

namespace OmEngine {
class OmButton : public QPushButton {
  Q_OBJECT
 public:
  explicit OmButton(QWidget* parent = nullptr);
  OmButton(const QString& button_text, QWidget* parent = nullptr);
  ~OmButton();

  void SetOffsetSide(const OmEngine::Side& side);
  void SetOffsetDistance(const OmEngine::OffsetDistance& offset_distance);

 private:
  OmEngine::Side offset_side_;
  OmEngine::OffsetDistance offset_distance_;
};
}

#endif  // OM_BUTTON_H
