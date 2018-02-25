#include <main_label.h>

#include <main_frame_geometries.h>
#include <widget_customizer.h>

using namespace client_code;

MainLabel::MainLabel(QWidget *parent)
    : QLabel(parent),
      main_label_animator_(new StateAnimator(this, false)),
      text_animator_(new TextAnimator(this, text_animation_delay_msec_)),
      main_label_scaler_(new Scaler(AxesRatio(0.0, 0.0), AxesRatio(0.75, 1.0),
                                    scaling::kRight,
                                    scaling::kRight | scaling::kDown)) {
  SetLabel();
}

MainLabel::~MainLabel() {
  delete main_label_scaler_;
  delete font_size_generator_;
}

void MainLabel::ScaleMainLabel(const DeltaSize &delta_size) {
  main_label_scaler_->SetDeltaSize(delta_size);
  main_label_scaler_->ComputeModification(GetMainLabelRect());

  if (!main_label_animator_->IsWidgetOpen()) {
    close();
  }

  setGeometry(main_label_scaler_->GetModifiedRect());
  main_label_animator_->SetCurrentGeometry(geometry());
  font_size_generator_->GenerateFontSize(this);
}

void MainLabel::Open() { main_label_animator_->Open(); }

void MainLabel::Close() { main_label_animator_->Close(); }

void MainLabel::DisplayText() {
  text_animator_->SetAnimationText(text());
  text_animator_->RunAnimation(this);
}

void MainLabel::Clear() {
  text_animator_->ResetAnimation();
  clear();
}

void MainLabel::SetLabel() {
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setWordWrap(true);
  WidgetCustomizer::CustomizeMainLabel(this, GetMainLabelRect());
  main_label_animator_->SetAnimation(QEasingCurve::OutCirc, 500,
                                     om_animation::kRight, om_animation::kLeft);
  main_label_animator_->SetCurrentGeometry(this->geometry());
  font_size_generator_ = new FontSizeGenerator(0.8, *this);
}
