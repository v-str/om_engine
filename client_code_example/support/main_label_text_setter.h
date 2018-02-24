#ifndef MAIN_LABEL_TEXT_SETTER_H
#define MAIN_LABEL_TEXT_SETTER_H

#include <QObject>

#include <main_label.h>

namespace client_code {

class MainLabelTextSetter : public QObject {
  Q_OBJECT
 public:
  MainLabelTextSetter(MainLabel* main_label, QObject* parent = nullptr);
  ~MainLabelTextSetter();

 public slots:
  void SetAbout();

 private:
  MainLabel* main_label_ = nullptr;
};
}

#endif  // MAIN_LABEL_TEXT_SETTER_H
