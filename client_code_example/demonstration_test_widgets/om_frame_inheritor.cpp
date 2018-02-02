#include <om_frame_inheritor.h>

#include <QFont>

#include <test_message.h>
#include <widget_customizer.h>

using namespace om_widgets;
using namespace om_animation;
using namespace demo_code;
using namespace scaling;

om_widgets::OmFrameInheritor::OmFrameInheritor(QWidget *parent,
                                               bool is_widget_open)
    : OmFrame(parent, is_widget_open),
      test_label_(new QLabel(this)),
      animator_(new StateAnimator(test_label_, false)),
      open_button_(new ClickButton("Open", this)),
      close_button_(new ClickButton("Close", this)),
      display_text_button_(new ClickButton("Info", this)),
      clear_text_button_(new ClickButton("Clear", this)),
      text_animator1_(new TextAnimator(this, text_animation_delay_msec_)),
      scaler_(new Scaler(AxesRatio(0.0, 0.0), AxesRatio(1.0, 1.0),
                         scaling::kRight, scaling::kRight | scaling::kDown)) {
  SetFrame();
  SetWidgets();
  SetLabelAnimation();
  SetConnections();
}

om_widgets::OmFrameInheritor::~OmFrameInheritor() {
  delete scaler_;
  delete font_size_generator_;
}

void OmFrameInheritor::ModifyGeometry(const QRect &initial_geometry,
                                      const DeltaSize &delta_size) {
  OmFrame::ModifyGeometry(initial_geometry, delta_size);
  ScaleTestLabel(delta_size);
}

void om_widgets::OmFrameInheritor::DisplayText() {
  text_animator1_->RunAnimation(test_label_);
}

void OmFrameInheritor::ClearTestLabel() {
  text_animator1_->ResetAnimation();
  test_label_->clear();
}

void om_widgets::OmFrameInheritor::SetFrame() {
  WidgetCustomizer::CustomizeFrame(this, QRect(0, 0, 0, 0));
  resize(500, 300);
}

void om_widgets::OmFrameInheritor::SetWidgets() {
  WidgetCustomizer::CustomizeButton(open_button_, QRect(30, 10, 95, 30));
  WidgetCustomizer::CustomizeButton(close_button_, QRect(135, 10, 95, 30));
  WidgetCustomizer::CustomizeButton(display_text_button_,
                                    QRect(240, 10, 95, 30));
  WidgetCustomizer::CustomizeButton(clear_text_button_, QRect(345, 10, 95, 30));
  WidgetCustomizer::CustomizeTestLabel(test_label_, QRect(30, 100, 500, 190));
}

void om_widgets::OmFrameInheritor::SetLabelAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, om_animation::kRight,
                          om_animation::kLeft);
  animator_->SetCurrentGeometry(test_label_->geometry());
  text_animator1_->SetAnimationText(
      "Spaceship cargo terminal A213:<br/><br/>"
      "Explosive class: A1<br/>"
      "Scanning power: 75%<br/>"
      "Cargo stream speed: 10pt<br/>"
      "Oxygen independence level: 10<br/>"
      "Main gate status: <font color=\"red\">CHECK</font>");
  font_size_generator_ = new FontSizeGenerator(0.8, *test_label_);
}

void om_widgets::OmFrameInheritor::SetConnections() {
  connect(close_button_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  connect(open_button_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));
  connect(display_text_button_, SIGNAL(clicked(bool)), SLOT(DisplayText()));
  connect(clear_text_button_, SIGNAL(clicked(bool)), SLOT(ClearTestLabel()));
}

void OmFrameInheritor::ScaleTestLabel(const DeltaSize &delta_size) {
  scaler_->SetDeltaSize(delta_size);
  scaler_->ComputeModification(QRect(30, 100, 500, 190));

  if (!animator_->IsWidgetOpen()) {
    test_label_->close();
  }

  test_label_->setGeometry(scaler_->GetModifiedRect());
  animator_->SetCurrentGeometry(test_label_->geometry());
  font_size_generator_->GenerateFontSize(test_label_);
}
