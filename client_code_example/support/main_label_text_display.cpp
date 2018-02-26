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
      "Cargo terminal status:\n\n"
      "Power supply...............On\n"
      "Reserve power supply.......Active\n"
      "Depressurization sensor....Active\n"
      "Main Gate shutter.........[CHECK]\n"
      "Number of operating\n"
      "spacesuits.................5\n"
      "Number of operating\n"
      "androids...................2");
  main_label_->DisplayText();
}

void MainLabelTextDisplay::DisplayEquipmentButton() {
  main_label_->Clear();
  main_label_->setText(
      "Cargo terminal equipment:\n\n"
      "Plasma cutter..............3\n"
      "Ion cutter.................2\n"
      "Assembly bay...............1\n"
      "Spacesuit..................6\n"
      "Android-repairer...........5\n"
      "Power loader...............2\n");
  main_label_->DisplayText();
}

void MainLabelTextDisplay::DisplayStuff() {
  main_label_->Clear();
  main_label_->setText(
      "Cargo terminal stuff:\n\n"
      "Sergeant A. Wasko\n\n"
      "private G. Stivenson\n"
      "private M. Lourens\n\n"
      "android SFP-25B/2-1\n"
      "android SFP-25B/2-2\n");
  main_label_->DisplayText();
}
