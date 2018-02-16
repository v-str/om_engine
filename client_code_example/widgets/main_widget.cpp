#include <main_widget.h>

#include <date_label.h>
#include <main_widget_geometries.h>
#include <shifter.h>
#include <time_label.h>
#include <widget_customizer.h>

using namespace client_code;

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent),
      main_frame_(new MainFrame(this, false)),
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

MainWidget::~MainWidget() { delete shifter_; }

void MainWidget::resizeEvent(QResizeEvent*) {
  main_frame_->ModifyGeometry(MainFrameGeometry(), GetDeltaSize());
  ShiftClocks();
}

void MainWidget::paintEvent(QPaintEvent*) {
  QPainter painter_(this);
  painter_.setRenderHint(QPainter::Antialiasing);
  painter_.save();
  painter_.drawPixmap(rect(), pixmap_);
  painter_.restore();
}

void MainWidget::SetAppearance() {
  pixmap_.load(":/resources/cargo_space_terminal.jpg");
  palette_.setBrush(QPalette::Background, pixmap_);
  this->setPalette(palette_);

  WidgetCustomizer::CustomizeFrame(main_frame_, MainFrameGeometry());
  WidgetCustomizer::CustomizeButton(button_open_, OpenButtonGeometry());
  WidgetCustomizer::CustomizeButton(button_close_, CloseButtonGeometry());
  WidgetCustomizer::CustomizeLabel(time_label_, TimeLabelGeometry());
  WidgetCustomizer::CustomizeLabel(date_label_, DateLabelGeometry());

  setMinimumSize(MainWidgetGeometry().width(), MainWidgetGeometry().height());
}

void MainWidget::SetWidgets() {
  setGeometry(MainWidgetGeometry());
  main_frame_->SetStretchFactor(scaling::AxesRatio(1.0, 1.0));
  main_frame_->StretchTo(scaling::kRight | scaling::kDown);

  shifter_->SetAxesRatio(scaling::AxesRatio(1.0, 0.0));
  shifter_->ModifyTo(scaling::kRight);
}

void MainWidget::SetAnimation() {
  main_frame_->SetAnimation(QEasingCurve::OutCirc);
  main_frame_->SetCurrentGeometry(main_frame_->geometry());
}

void MainWidget::SetConnections() {
  connect(button_close_, SIGNAL(clicked(bool)), main_frame_, SLOT(Close()));
  connect(button_open_, SIGNAL(clicked(bool)), main_frame_, SLOT(Open()));
}

void MainWidget::ShiftClocks() {
  shifter_->SetDeltaSize(GetDeltaSize());
  shifter_->ComputeModification(DateLabelGeometry());

  date_label_->setGeometry(shifter_->GetModifiedRect());

  int distance = DateLabelGeometry().x() - TimeLabelGeometry().x();
  int margin = distance - TimeLabelGeometry().width();
  int new_time_x_pos = date_label_->x() - TimeLabelGeometry().width() - margin;

  time_label_->move(new_time_x_pos, TimeLabelGeometry().y());
}

DeltaSize MainWidget::GetDeltaSize() {
  return DeltaSize(width() - MainWidgetGeometry().width(),
                   height() - MainWidgetGeometry().height());
}
