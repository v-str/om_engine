#include <om_button.h>

using namespace OmEngine;

OmButton::OmButton(QWidget* parent) : QPushButton(parent) {}

OmButton::OmButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

OmButton::~OmButton() {}

void OmButton::SetOffsetSide(const Side& side) { offset_side_ = side; }
