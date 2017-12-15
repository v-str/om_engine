#include <test_frame.h>

TestFrame::TestFrame(QWidget* parent)
    : QFrame(parent),
      test_label_(new QLabel("om engine library", this)),
      animator_(new WidgetAnimator(test_label_, true)),
      open_button_(new OmButton("open", this)),
      close_button_(new OmButton("close", this)) {
  SetTestFrame();
  SetWidgets();
  SetLabel();
  SetAnimation();
  SetConnections();
}

TestFrame::~TestFrame() {}

void TestFrame::SetTestFrame() {
  resize(500, 300);
  setStyleSheet(
      "QWidget {"
      "background: black;"
      "border: 2px solid green;"
      "border-radius: 5px;"
      "}");
}

void TestFrame::SetWidgets() {
  open_button_->setGeometry(30, 30, 100, 20);
  open_button_->setStyleSheet(
      "QPushButton{"
      "background-color: grey;"
      "border: 2px solid green;"
      "border-radius: 5px;"
      "}");
  open_button_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  open_button_->SetOffsetSide(om_utility::Side::kRight |
                              om_utility::Side::kDown);

  close_button_->setGeometry(140, 30, 100, 20);
  close_button_->setStyleSheet(
      "QPushButton{"
      "background-color: grey;"
      "border: 2px solid green;"
      "border-radius: 5px;"
      "}");
  close_button_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  close_button_->SetOffsetSide(om_utility::Side::kRight |
                               om_utility::Side::kDown);

  test_label_->setGeometry(30, 100, 440, 150);
  test_label_->setAlignment(Qt::AlignCenter);
}

void TestFrame::SetLabel() {
  test_label_->setStyleSheet(
      "QLabel{"
      "border: 1px solid green;"
      "color: green;"
      "}");
}

void TestFrame::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, kRight, kLeft);
  animator_->SetCurrentGeometry(test_label_->geometry());
}

void TestFrame::SetConnections() {
  connect(close_button_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  connect(open_button_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));
}
