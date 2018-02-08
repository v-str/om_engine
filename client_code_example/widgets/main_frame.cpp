#include <main_frame.h>

#include <main_frame_geometries.h>
#include <widget_customizer.h>

using namespace client_code;
using namespace om_animation;
using namespace scaling;
using namespace om_widgets;

MainFrame::MainFrame(QWidget *parent, bool is_widget_open)
    : OmFrame(parent, is_widget_open),
      main_label_(new QLabel(this)),
      animator_(new StateAnimator(main_label_, false)),
      button_frame_(new ButtonFrame(this)),
      text_animator1_(new TextAnimator(this, text_animation_delay_msec_)),
      scaler_(new Scaler(AxesRatio(0.0, 0.0), AxesRatio(1.0, 1.0),
                         scaling::kRight, scaling::kRight | scaling::kDown)) {
  SetWidgets();
  SetLabelAnimation();
  SetConnections();
}

MainFrame::~MainFrame() {
  delete scaler_;
  delete font_size_generator_;
}

void MainFrame::ModifyGeometry(const QRect &initial_geometry,
                               const DeltaSize &delta_size) {
  OmFrame::ModifyGeometry(initial_geometry, delta_size);
  ScaleTestLabel(delta_size);
}

void MainFrame::DisplayText() { text_animator1_->RunAnimation(main_label_); }

void MainFrame::ClearTestLabel() {
  text_animator1_->ResetAnimation();
  main_label_->clear();
}

void MainFrame::SetWidgets() {
  WidgetCustomizer::CustomizeButtonFrame(button_frame_);
  WidgetCustomizer::CustomizeTestLabel(main_label_, MainLabel());
  resize(500, 300);
}

void MainFrame::SetLabelAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, om_animation::kRight,
                          om_animation::kLeft);
  animator_->SetCurrentGeometry(main_label_->geometry());
  text_animator1_->SetAnimationText(WidgetCustomizer::GetAnimationText());
  font_size_generator_ = new FontSizeGenerator(0.8, *main_label_);
}

void MainFrame::SetConnections() {
  connect(button_frame_->OpenButton(), SIGNAL(clicked(bool)), animator_,
          SLOT(Open()));
  connect(button_frame_->CloseButton(), SIGNAL(clicked(bool)), animator_,
          SLOT(Close()));
  connect(button_frame_->AboutButton(), SIGNAL(clicked(bool)),
          SLOT(DisplayText()));
  connect(button_frame_->ClearButton(), SIGNAL(clicked(bool)),
          SLOT(ClearTestLabel()));
}

void MainFrame::ScaleTestLabel(const DeltaSize &delta_size) {
  scaler_->SetDeltaSize(delta_size);
  scaler_->ComputeModification(MainLabel());

  if (!animator_->IsWidgetOpen()) {
    main_label_->close();
  }

  main_label_->setGeometry(scaler_->GetModifiedRect());
  animator_->SetCurrentGeometry(main_label_->geometry());
  font_size_generator_->GenerateFontSize(main_label_);
}
