#include <main_label_text_setter.h>

using namespace client_code;

MainLabelTextSetter::MainLabelTextSetter(MainLabel *main_label, QObject *parent)
    : main_label_(main_label), QObject(parent) {}

MainLabelTextSetter::~MainLabelTextSetter() {}

void MainLabelTextSetter::SetAbout() {
  main_label_->Clear();
  main_label_->setText(
      "Description: Spaceship cargo terminal serves for storing "
      "and repairing transports or spaceship equipment\n\n"
      "Year of manufacture:    2073\n"
      "Planet:      Mars, G-300");
  main_label_->DisplayText();
}
