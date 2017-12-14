﻿#include <test_widget.h>

TestWidget::TestWidget(QWidget* parent)
    : QWidget(parent),
      test_frame_(new QFrame(this)),
      test_label_(new QLabel("om engine library", test_frame_)),
      close_animator_(new WidgetAnimator(test_frame_)),
      open_animator_(new WidgetAnimator(test_frame_)),
      button_open_(new OmButton("Open!", this)),
      button_close_(new OmButton("Close!", this)) {
  SetAppearance();
  SetWidgets();
  SetAnimation();
  SetConnections();
}

TestWidget::~TestWidget() {}

void TestWidget::SetAppearance() {
  setStyleSheet(
      "QWidget {"
      "background: black;"
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

void TestWidget::SetWidgets() {
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

void TestWidget::SetAnimation() {
  close_animator_->SetAnimation(om_utility::WidgetAnimationType::kClose,
                                QEasingCurve::OutCirc, 500, om_utility::kLeft);
  close_animator_->SetCurrentGeometry(test_frame_->geometry());

  open_animator_->SetAnimation(om_utility::WidgetAnimationType::kOpen,
                               QEasingCurve::OutCirc, 500, om_utility::kRight);
  open_animator_->SetCurrentGeometry(test_frame_->geometry());
}

void TestWidget::SetConnections() {
  QObject::connect(button_close_, SIGNAL(clicked(bool)), close_animator_,
                   SLOT(Close()));
  QObject::connect(button_open_, SIGNAL(clicked(bool)), open_animator_,
                   SLOT(Open()));
}
