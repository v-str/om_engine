#ifndef MAIN_LABEL_TEXT_DISPLAY_H
#define MAIN_LABEL_TEXT_DISPLAY_H

#include <QObject>

#include <main_label.h>

namespace client_code {

class MainLabelTextDisplay : public QObject {
  Q_OBJECT
 public:
  MainLabelTextDisplay(MainLabel* main_label, QObject* parent = nullptr);
  ~MainLabelTextDisplay();

 public slots:
  void DisplayAbout();
  void DisplayStatus();

 private:
  MainLabel* main_label_ = nullptr;
};
}

#endif  // MAIN_LABEL_TEXT_DISPLAY_H
