#include <om_frame_inheritor.h>

#include <QFont>

#include <test_message.h>
#include <test_widget_setter.h>

using namespace om_widgets;
using namespace om_animation;
using namespace demo_code;
using namespace scaling;

om_widgets::OmFrameInheritor::OmFrameInheritor(QWidget *parent,
                                               bool is_widget_open)
    : OmFrame(parent, is_widget_open),
      test_label_(new QLabel(this)),
      animator_(new StateAnimator(test_label_, false)),
      open_button_(new ClickButton("Open frame", this)),
      close_button_(new ClickButton("Close frame", this)),
      display_text_button_(new ClickButton("Display text", this)),
      text_animator1_(new TextAnimator(this, text_animation_delay_msec_)),
      scaler_(new Scaler(AxesRatio(0.0, 0.0), AxesRatio(1.0, 1.0),
                         scaling::kRight, scaling::kRight | scaling::kDown)) {
  SetFrame();
  SetWidgets();
  SetLabelAnimation();
  SetConnections();
}

om_widgets::OmFrameInheritor::~OmFrameInheritor() { delete scaler_; }

void OmFrameInheritor::ModifyGeometry(const QRect &initial_geometry,
                                      const DeltaSize &delta_size) {
  OmFrame::ModifyGeometry(initial_geometry, delta_size);
  ScaleTestLabel(delta_size);
}

void om_widgets::OmFrameInheritor::DisplayText() {
  text_animator1_->RunAnimation(test_label_);
}

void om_widgets::OmFrameInheritor::SetFrame() {
  TestWidgetSetter::CustomizeFrame(this, QRect(0, 0, 0, 0));
  resize(500, 300);
}

void om_widgets::OmFrameInheritor::SetWidgets() {
  TestWidgetSetter::CustomizeButton(open_button_, QRect(30, 10, 95, 30));
  TestWidgetSetter::CustomizeButton(close_button_, QRect(135, 10, 95, 30));
  TestWidgetSetter::CustomizeButton(display_text_button_,
                                    QRect(240, 10, 95, 30));
  TestWidgetSetter::CustomizeTestLabel(test_label_, QRect(30, 100, 500, 190));
}

void om_widgets::OmFrameInheritor::SetLabelAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, om_animation::kRight,
                          om_animation::kLeft);
  animator_->SetCurrentGeometry(test_label_->geometry());
  text_animator1_->SetAnimationText(
      "Transitive spaceship module A213\n"
      "Internal state data:\n"
      "Temperature: 19.5\n"
      "Pressure: 630mm\n"
      "Delta TA: 12%\n"
      "External state data:\n"
      "Temperature: -270,85\n"
      "Pressure: 0,264mm\n"
      "Delta TA: 195%");
}

void om_widgets::OmFrameInheritor::SetConnections() {
  connect(close_button_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  connect(open_button_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));
  connect(display_text_button_, SIGNAL(clicked(bool)), SLOT(DisplayText()));
}

void OmFrameInheritor::ScaleTestLabel(const DeltaSize &delta_size) {
  scaler_->SetDeltaSize(delta_size);
  scaler_->ComputeModification(QRect(30, 100, 500, 190));

  if (!animator_->IsWidgetOpen()) {
    test_label_->close();
  }

  test_label_->setGeometry(scaler_->GetModifiedRect());
  animator_->SetCurrentGeometry(test_label_->geometry());
}
