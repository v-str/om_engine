#include <main_test_widget.h>

#include <QDebug>

#include <QPalette>
#include <QPixmap>

static unsigned int kCount = 0;

MainTestWidget::MainTestWidget(QWidget* parent)
    : QWidget(parent),
      test_frame_(new TestFrame(this)),
      animator_(new WidgetAnimator(test_frame_, true)),
      button_open_(new OmButton("Open", this)),
      button_close_(new OmButton("Close", this)) {
  SetAppearance();
  SetWidgets();
  SetAnimation();
  SetConnections();
}

MainTestWidget::~MainTestWidget() {}

void MainTestWidget::MultipleClickCathed() {
  qDebug() << "Multiple click on the same button!" << kCount;
  ++kCount;
}

void MainTestWidget::SetAppearance() {
  QPixmap background("://resources/abstract_technology_background.jpg");
  QPalette palette;
  palette.setBrush(QPalette::Background, background);
  this->setPalette(palette);

  //  setStyleSheet(
  //      "QWidget {"
  //      "background-image:
  //      url(:/resources/abstract_technology_background.jpg);"
  //      "}");

  test_frame_->setStyleSheet(
      "QFrame{"
      "background: transparent;"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");

  button_close_->setStyleSheet(
      "QPushButton{"
      "background-color: transparent;"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
  button_open_->setStyleSheet(
      "QPushButton{"
      "background-color: transparent;"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
}

void MainTestWidget::SetWidgets() {
  resize(600, 400);

  test_frame_->setGeometry(20, 70, 560, 320);

  button_open_->setGeometry(20, 10, 70, 30);
  button_close_->setGeometry(100, 10, 70, 30);

  button_open_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  button_open_->SetOffsetSide(om_utility::Side::kRight |
                              om_utility::Side::kDown);
  button_close_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  button_close_->SetOffsetSide(om_utility::Side::kRight |
                               om_utility::Side::kDown);
}

void MainTestWidget::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500);
  animator_->SetCurrentGeometry(test_frame_->geometry());
}

void MainTestWidget::SetConnections() {
  connect(button_close_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  connect(button_open_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));

  connect(animator_, SIGNAL(AnimationIncomplete()),
          SLOT(MultipleClickCathed()));
}
