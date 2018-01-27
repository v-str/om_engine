#include <main_test_widget.h>

#include <QPalette>
#include <QPixmap>

#include <date_label.h>
#include <test_geometries.h>
#include <test_message.h>
#include <test_widget_setter.h>
#include <time_label.h>

using namespace demo_code;

MainTestWidget::MainTestWidget(QWidget* parent)
    : QWidget(parent),
      inheritor_(new OmFrameInheritor(this, false)),
      button_open_(new ClickButton("Open", this)),
      button_close_(new ClickButton("Close", this)),
      time_label_(new TimeLabel(this)),
      date_label_(new DateLabel(this)) {
  SetAppearance();
  SetWidgets();
  SetAnimation();
  SetConnections();
}

MainTestWidget::~MainTestWidget() {}

void MainTestWidget::resizeEvent(QResizeEvent*) {}

void MainTestWidget::MultipleClickCathed() {
  TestMessage::WriteTestMessage(
      "Repetitive click on the same button was caught");
}

void MainTestWidget::SetAppearance() {
  QPixmap background("://resources/the_monster.jpg");
  QPalette palette;
  palette.setBrush(QPalette::Background, background);
  this->setPalette(palette);

  TestWidgetSetter::CustomizeFrame(inheritor_, TestFrameGeometry());
  TestWidgetSetter::CustomizeButton(button_open_, OpenButtonGeometry());
  TestWidgetSetter::CustomizeButton(button_close_, CloseButtonGeometry());
  TestWidgetSetter::CustomizeLabel(time_label_, TimeLabelGeometry());
  TestWidgetSetter::CustomizeLabel(date_label_, DateLabelGeometry());
}

void MainTestWidget::SetWidgets() { setGeometry(MainWidgetGeometry()); }

void MainTestWidget::SetAnimation() {
  inheritor_->SetAnimation(QEasingCurve::OutCirc);
  inheritor_->SetCurrentGeometry(inheritor_->geometry());
}

void MainTestWidget::SetConnections() {
  connect(button_close_, SIGNAL(clicked(bool)), inheritor_, SLOT(Close()));
  connect(button_open_, SIGNAL(clicked(bool)), inheritor_, SLOT(Open()));
}

DeltaSize MainTestWidget::GetDeltaSize() {
  return DeltaSize(width() - MainWidgetGeometry().width(),
                   height() - MainWidgetGeometry().height());
}
