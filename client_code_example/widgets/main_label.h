#ifndef MAIN_LABEL_H
#define MAIN_LABEL_H

#include <QLabel>

namespace client_code {

// using namespace om_widgets;
// using namespace om_animation;

class MainLabel : public QLabel {
  Q_OBJECT
 public:
  MainLabel(QLabel* parent = nullptr);
  ~MainLabel();

 private:
};
}

#endif  // MAIN_LABEL_H
