#include <main_label_text_display.h>

using namespace client_code;

MainLabelTextDisplay::MainLabelTextDisplay(MainLabel *main_label,
                                           QObject *parent)
    : main_label_(main_label), QObject(parent) {}

MainLabelTextDisplay::~MainLabelTextDisplay() {}

void MainLabelTextDisplay::DisplayAbout() {
  main_label_->Clear();
  main_label_->setText(
      "Description: Spaceship cargo terminal serves for storing "
      "and repairing transports or spaceship equipment\n\n"
      "Year of manufacture:    2073\n"
      "Planet:      Mars, G-300");
  main_label_->DisplayText();
}

void MainLabelTextDisplay::DisplayStatus() {
  main_label_->Clear();
  main_label_->setText(
      "Power supply...............On\n"
      "Reserve power supply.......Active\n"
      "Depressurization sensor....Active\n"
      "Main Gate shutter..........CHECK\n"
      "Number of operating\n"
      "spacesuits.................5\n"
      "Number of operating\n"
      "androids...................2");
  main_label_->DisplayText();
}
