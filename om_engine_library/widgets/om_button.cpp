#include <om_button.h>

using namespace OmEngine;

OmButton::OmButton(QWidget* parent) : QPushButton(parent) {}

OmButton::OmButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

void OmButton::SetOffsetSide(unsigned int offset_side) {
  offset_side_ = offset_side;
}

OmButton::~OmButton() {}
