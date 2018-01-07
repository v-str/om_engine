#include <main_test_widget.h>

#include <QPalette>
#include <QPixmap>

#include <geometry_controller.h>
#include <test_geometries.h>
#include <test_message.h>
#include <test_widget_setter.h>

using namespace demo_code;

MainTestWidget::MainTestWidget(QWidget* parent)
    : QWidget(parent),
      test_frame_(new TestFrame(this)),
      animator_(new WidgetAnimator(test_frame_, false)),
      button_open_(new OmButton("Open", this)),
      button_close_(new OmButton("Close", this)),
      time_label_(new OmTimeLabel(this)),
      date_label_(new OmDateLabel(this)) {
  SetAppearance();
  SetWidgets();
  SetAnimation();
  SetConnections();
}

MainTestWidget::~MainTestWidget() {}

void MainTestWidget::resizeEvent(QResizeEvent*) {
  GeometryController::SetDeltaSize(GetDeltaSize());
  GeometryController::ShiftGeometry(TimeLabelGeometry(), time_label_);
  GeometryController::ShiftGeometry(DateLabelGeometry(), date_label_);
  GeometryController::StretchGeometry(TestFrameGeometry(), test_frame_);
}

void MainTestWidget::MultipleClickCathed() {
  TestMessage::WriteTestMessage(
      "Repetitive click on the same button was caught");
}

void MainTestWidget::SetAppearance() {
  QPixmap background("://resources/abstract_technology_background.jpg");
  QPalette palette;
  palette.setBrush(QPalette::Background, background);
  this->setPalette(palette);

  TestWidgetSetter::CustomizeFrame(test_frame_, TestFrameGeometry());
  TestWidgetSetter::CustomizeButton(button_open_, OpenButtonGeometry());
  TestWidgetSetter::CustomizeButton(button_close_, CloseButtonGeometry());
  TestWidgetSetter::CustomizeLabel(time_label_, TimeLabelGeometry());
  TestWidgetSetter::CustomizeLabel(date_label_, DateLabelGeometry());
}

void MainTestWidget::SetWidgets() { setGeometry(MainWidgetGeometry()); }

void MainTestWidget::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc);
  animator_->SetCurrentGeometry(test_frame_->geometry());
}

void MainTestWidget::SetConnections() {
  connect(button_close_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  connect(button_open_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));
  connect(animator_, SIGNAL(AnimationComplete()), test_frame_, SLOT(show()));
  connect(animator_, SIGNAL(AnimationIncomplete()),
          SLOT(MultipleClickCathed()));
}

DeltaSize MainTestWidget::GetDeltaSize() {
  return DeltaSize(width() - MainWidgetGeometry().width(),
                   height() - MainWidgetGeometry().height());
}
