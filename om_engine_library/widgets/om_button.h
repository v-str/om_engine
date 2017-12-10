#ifndef OM_BUTTON_H
#define OM_BUTTON_H

#include <QPushButton>

namespace OmEngine {
class OmButton : public QPushButton {
  Q_OBJECT
 public:
  explicit OmButton(QWidget* parent = nullptr);
  OmButton(const QString& button_text, QWidget* parent = nullptr);

  void SetOffsetSide(unsigned int offset_side);

  ~OmButton();

 private:
  enum OffsetSide { kNone = 0, kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

  unsigned int offset_side_ = 0;
};
}

#endif  // OM_BUTTON_H
