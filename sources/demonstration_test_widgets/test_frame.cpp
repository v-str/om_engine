#include <test_frame.h>

TestFrame::TestFrame(QWidget* parent)
    : QFrame(parent),
      test_label_(new QLabel(this)),
      animator_(new WidgetAnimator(test_label_, true)),
      open_button_(new OmButton(this)),
      close_button_(new OmButton(this)),
      display_text_button_(new OmButton("display text", this)) {
  SetTestFrame();
  SetWidgets();
  SetLabel();
  SetAnimation();
  SetConnections();

  text_animator1_ = new TextAnimator(this);
  text_animator2_ = new TextAnimator(this);
  text_animator3_ = new TextAnimator(this);
}

TestFrame::~TestFrame() {
  delete text_animator1_;
  delete text_animator2_;
  delete text_animator3_;
}

void TestFrame::DisplayText() {
  text_animator1_->SetAnimationDelay(50);

  text_animator1_->SetAnimationText("Ordinary Mind is greeting you . . .");
  text_animator1_->RunAnimation(test_label_);

  emit DisplayOpenButtonText();
}

void TestFrame::AnimateOpenButton() {
  text_animator2_->SetAnimationDelay(100);
  text_animator2_->SetAnimationText("Open it");
  text_animator2_->RunAnimation(open_button_);

  emit DisplayCloseButtonText();
}

void TestFrame::AnimateCloseButton() {
  text_animator3_->SetAnimationDelay(100);
  text_animator3_->SetAnimationText("Close it");
  text_animator3_->RunAnimation(close_button_);
}

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

  display_text_button_->setGeometry(250, 30, 100, 20);
  display_text_button_->setStyleSheet(
      "QPushButton{"
      "background-color: grey;"
      "border: 2px solid green;"
      "border-radius: 5px;"
      "}");
  display_text_button_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  display_text_button_->SetOffsetSide(om_utility::Side::kRight |
                                      om_utility::Side::kDown);

  test_label_->setGeometry(30, 100, 440, 150);
  test_label_->setAlignment(Qt::AlignCenter);
  test_label_->setWordWrap(true);
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
  connect(display_text_button_, SIGNAL(clicked(bool)), SLOT(DisplayText()));
  connect(this, SIGNAL(DisplayOpenButtonText()), SLOT(AnimateOpenButton()));
  connect(this, SIGNAL(DisplayCloseButtonText()), SLOT(AnimateCloseButton()));
}
