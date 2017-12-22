﻿#include <test_frame.h>

#include <QFont>

#include <test_message.h>

TestFrame::TestFrame(QWidget* parent)
    : QFrame(parent),
      test_label_(new QLabel(this)),
      animator_(new WidgetAnimator(test_label_, true)),
      open_button_(new OmButton("Open frame", this)),
      close_button_(new OmButton("Close frame", this)),
      display_text_button_(new OmButton("Display text", this)),
      text_animator1_(new TextAnimator(this, 30)) {
  SetTestFrame();
  SetWidgets();
  SetLabel();
  SetAnimation();
  SetConnections();
}

TestFrame::~TestFrame() { delete text_animator1_; }

void TestFrame::DisplayTextByPublicMethod() {
  text_animator1_->SetAnimationText("Ordinary Mind is greeting you . . .");
  text_animator1_->RunAnimation(test_label_);
}

void TestFrame::IsAnimationComplete() {
  TestMessage::WriteTestMessage(
      "test_label_ text animation test by method "
      "complete . . . ");
}

void TestFrame::SetTestFrame() {
  resize(500, 300);
  setStyleSheet(
      "QWidget {"
      "background: transparent;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
}

void TestFrame::SetWidgets() {
  open_button_->setGeometry(30, 10, 95, 30);
  open_button_->setStyleSheet(
      "QPushButton{"
      "background-color: transparent;"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
  open_button_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  open_button_->SetOffsetSide(om_utility::Side::kRight |
                              om_utility::Side::kDown);

  close_button_->setGeometry(135, 10, 95, 30);
  close_button_->setStyleSheet(
      "QPushButton{"
      "background-color: transparent;"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
  close_button_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  close_button_->SetOffsetSide(om_utility::Side::kRight |
                               om_utility::Side::kDown);

  display_text_button_->setGeometry(240, 10, 95, 30);
  display_text_button_->setStyleSheet(
      "QPushButton{"
      "background-color: transparent;"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
  display_text_button_->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  display_text_button_->SetOffsetSide(om_utility::Side::kRight |
                                      om_utility::Side::kDown);

  test_label_->setGeometry(30, 100, 500, 190);
  test_label_->setAlignment(Qt::AlignCenter);
  test_label_->setWordWrap(true);
}

void TestFrame::SetLabel() {
  test_label_->setStyleSheet(
      "QLabel{"
      "border: 2px solid #00FFFF;"
      "color: #0000CC;"
      "}");

  QFont font = test_label_->font();
  font.setPointSize(20);

  test_label_->setFont(font);
}

void TestFrame::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, kRight, kLeft);
  animator_->SetCurrentGeometry(test_label_->geometry());
}

void TestFrame::SetConnections() {
  connect(close_button_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  connect(open_button_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));
  connect(display_text_button_, SIGNAL(clicked(bool)),
          SLOT(DisplayTextByPublicMethod()));
  connect(text_animator1_, SIGNAL(TextAnimationComplete()),
          SLOT(IsAnimationComplete()));
}
