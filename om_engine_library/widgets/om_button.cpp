#include <om_button.h>

OmButton::OmButton(QWidget* parent) : QPushButton(parent) {}

OmButton::OmButton(const QString& button_text, QWidget* parent)
    : QPushButton(button_text, parent) {}

OmButton::~OmButton() {}
