#include <main_test_widget.h>

#include <date_label.h>
#include <shifter.h>
#include <test_geometries.h>
#include <test_widget_setter.h>
#include <time_label.h>

#include <QDebug>

using namespace demo_code;

MainTestWidget::MainTestWidget(QWidget* parent)
    : QWidget(parent),
      inheritor_(new OmFrameInheritor(this, false)),
      button_open_(new ClickButton("Open", this)),
      button_close_(new ClickButton("Close", this)),
      time_label_(new TimeLabel(this)),
      date_label_(new DateLabel(this)),
      shifter_(new Shifter) {
  SetAppearance();
  SetWidgets();
  SetAnimation();
  SetConnections();
}

MainTestWidget::~MainTestWidget() { delete shifter_; }

void MainTestWidget::resizeEvent(QResizeEvent*) {
  inheritor_->ModifyGeometry(InheritorFrameGeometry(), GetDeltaSize());
  ShiftClocks();
}

void MainTestWidget::paintEvent(QPaintEvent*) {
  QPainter painter_(this);
  painter_.setRenderHint(QPainter::Antialiasing);
  painter_.save();
  painter_.drawPixmap(rect(), pixmap_);
  painter_.restore();
}

void MainTestWidget::SetAppearance() {
  pixmap_.load(":/resources/spaceship_coridor.jpg");
  palette_.setBrush(QPalette::Background, pixmap_);
  this->setPalette(palette_);

  TestWidgetSetter::CustomizeFrame(inheritor_, InheritorFrameGeometry());
  TestWidgetSetter::CustomizeButton(button_open_, OpenButtonGeometry());
  TestWidgetSetter::CustomizeButton(button_close_, CloseButtonGeometry());
  TestWidgetSetter::CustomizeLabel(time_label_, TimeLabelGeometry());
  TestWidgetSetter::CustomizeLabel(date_label_, DateLabelGeometry());
}

void MainTestWidget::SetWidgets() {
  setGeometry(MainWidgetGeometry());
  inheritor_->SetStretchFactor(scaling::AxesRatio(1.0, 1.0));
  inheritor_->StretchTo(scaling::kRight | scaling::kDown);

  shifter_->SetAxesRatio(scaling::AxesRatio(1.0, 0.0));
  shifter_->ModifyTo(scaling::kRight);
}

void MainTestWidget::SetAnimation() {
  inheritor_->SetAnimation(QEasingCurve::OutCirc);
  inheritor_->SetCurrentGeometry(inheritor_->geometry());
}

void MainTestWidget::SetConnections() {
  connect(button_close_, SIGNAL(clicked(bool)), inheritor_, SLOT(Close()));
  connect(button_open_, SIGNAL(clicked(bool)), inheritor_, SLOT(Open()));
}

void MainTestWidget::ShiftClocks() {
  shifter_->SetDeltaSize(GetDeltaSize());
  shifter_->ComputeModification(DateLabelGeometry());

  date_label_->setGeometry(shifter_->GetModifiedRect());

  int distance = DateLabelGeometry().x() - TimeLabelGeometry().x();
  int margin = distance - TimeLabelGeometry().width();
  int new_time_x_pos = date_label_->x() - TimeLabelGeometry().width() - margin;

  time_label_->move(new_time_x_pos, TimeLabelGeometry().y());
}

DeltaSize MainTestWidget::GetDeltaSize() {
  return DeltaSize(width() - MainWidgetGeometry().width(),
                   height() - MainWidgetGeometry().height());
}
