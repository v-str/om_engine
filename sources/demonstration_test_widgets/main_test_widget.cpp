#include <main_test_widget.h>

#include <QDebug>

static unsigned int kCount = 0;

MainTestWidget::MainTestWidget(QWidget* parent)
    : QWidget(parent),
      test_frame_(new QFrame(this)),
      test_label_(new QLabel("om engine library", test_frame_)),
      animator_(new WidgetAnimator(test_frame_, true)),
      button_open_(new OmButton("Open!", this)),
      button_close_(new OmButton("Close!", this)) {
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
  setStyleSheet(
      "QWidget {"
      "background: #202020;"
      "}");

  test_frame_->setStyleSheet(
      "QFrame{"
      "background: black;"
      "border: 2px solid green;"
      "border-radius: 5px;"
      "}");

  button_close_->setStyleSheet(
      "QPushButton{"
      "background-color: grey;"
      "border: 2px solid green;"
      "border-radius: 5px;"
      "}");
  button_open_->setStyleSheet(
      "QPushButton{"
      "background-color: grey;"
      "border: 2px solid green;"
      "border-radius: 5px;"
      "}");

  test_label_->setStyleSheet(
      "QLabel{"
      "border: 1px solid green;"
      "color: green;"
      "}");
}

void MainTestWidget::SetWidgets() {
  resize(600, 400);

  test_frame_->setGeometry(50, 50, 500, 300);

  button_open_->setGeometry(50, 10, 100, 20);
  button_close_->setGeometry(160, 10, 100, 20);

  test_label_->setGeometry(10, 10, 480, 280);
  test_label_->setAlignment(Qt::AlignCenter);

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
