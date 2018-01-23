#ifndef CLICK_BUTTON_H
#define CLICK_BUTTON_H

#include <QPushButton>

#include <offset_distance.h>

namespace om_widgets {

class ClickButton : public QPushButton {
  Q_OBJECT
 public:
  explicit ClickButton(QWidget* parent = nullptr);
  ClickButton(const QString& button_text, QWidget* parent = nullptr);
  ClickButton(const QString& button_text, const OffsetDistance& offset_distance,
              unsigned int offset_side, QWidget* parent = nullptr);

  ~ClickButton();

  void SetOffsetParameters(const OffsetDistance& offset_distance,
                           unsigned int offset_side);

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  unsigned int offset_side_;
  OffsetDistance offset_distance_;
};
}

#endif  // CLICK_BUTTON_H
