#include <main_test_widget.h>

#include <QDebug>
#include <QPalette>
#include <QPixmap>

#include <test_widget_setter.h>

static unsigned int kCount = 0;

MainTestWidget::MainTestWidget(QWidget* parent)
    : QWidget(parent),
      test_frame_(new TestFrame(this)),
      animator_(new WidgetAnimator(test_frame_, false)),
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

  TestWidgetSetter::ColorizeFrame(test_frame_, QRect(20, 70, 560, 320));
  TestWidgetSetter::ColorizeButton(button_close_, QRect(100, 10, 70, 30));
  TestWidgetSetter::ColorizeButton(button_open_, QRect(20, 10, 70, 30));
}

void MainTestWidget::SetWidgets() {
  resize(600, 400);
  test_frame_->close();
}

void MainTestWidget::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500);
  animator_->SetCurrentGeometry(test_frame_->geometry());
}

void MainTestWidget::SetConnections() {
  connect(button_close_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  // connect(animator_, SIGNAL(AnimationComplete()), test_frame_,
  // SLOT(close()));
  connect(button_open_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));
  connect(animator_, SIGNAL(AnimationComplete()), test_frame_, SLOT(show()));
  connect(animator_, SIGNAL(AnimationIncomplete()),
          SLOT(MultipleClickCathed()));
}
