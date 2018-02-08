#ifndef BUTTON_FRAME_H
#define BUTTON_FRAME_H

#include <QFrame>

namespace client_code {

class ButtonFrame : public QFrame {
  Q_OBJECT
 public:
  ButtonFrame(QFrame* parent = nullptr);
  ~ButtonFrame();

 private:
};
}

#endif  // BUTTON_FRAME_H
