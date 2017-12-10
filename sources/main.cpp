#include <QApplication>

#include <QWidget>

#include <om_button.h>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  QWidget widget;
  widget.setGeometry(600, 400, 600, 400);

  OmWidgets::OmButton* button_ = new OmWidgets::OmButton(&widget);
  button_->setText("OmButton");
  button_->setGeometry(50, 25, 100, 30);
  button_->SetOffsetSide(OmUtility::kRight | OmUtility::kUp);
  button_->SetOffsetDistance(OmUtility::OffsetDistance(5, 5));

  widget.show();

  return app.exec();
}
