#ifndef OM_BUTTON_H
#define OM_BUTTON_H

#include <QPushButton>

namespace OmEngine {
class OmButton : public QPushButton {
  Q_OBJECT
 public:
  explicit OmButton(QWidget* parent = nullptr);
  OmButton(const QString& button_text, QWidget* parent = nullptr);

  ~OmButton();
};
}

#endif  // OM_BUTTON_H
