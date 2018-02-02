#include <scaler.h>

#include <geometry_modifier.h>
#include <shifter.h>
#include <stretcher.h>

using namespace scaling;

Scaler::Scaler() : shifter_(new Shifter), stretcher_(new Stretcher) {
  shifter_->SetAxesRatio(AxesRatio(0.0, 0.0));
  shifter_->ModifyTo(kLeft);
  stretcher_->SetAxesRatio(AxesRatio(0.0, 0.0));
  stretcher_->ModifyTo(kLeft);
}

Scaler::Scaler(const AxesRatio &shift_ratio, const AxesRatio &stretch_ratio,
               unsigned int shift_to, unsigned int stretch_to)
    : shifter_(new Shifter), stretcher_(new Stretcher) {
  shifter_->SetAxesRatio(shift_ratio);
  shifter_->ModifyTo(shift_to);
  stretcher_->SetAxesRatio(stretch_ratio);
  stretcher_->ModifyTo(stretch_to);
}

Scaler::Scaler(Scaler &&scaler) {
  shifter_ = std::move(scaler.shifter_);
  stretcher_ = std::move(scaler.stretcher_);
}

Scaler &Scaler::operator=(Scaler &&scaler) {
  shifter_ = std::move(scaler.shifter_);
  stretcher_ = std::move(scaler.stretcher_);
  return *this;
}

void Scaler::ComputeModification(const QRect &initial_position) {
  shifter_->ComputeModification(initial_position);
  stretcher_->ComputeModification(initial_position);
}

QRect Scaler::GetModifiedRect() const {
  return QRect(shifter_->GetModifiedRect().x(), shifter_->GetModifiedRect().y(),
               stretcher_->GetModifiedRect().width(),
               stretcher_->GetModifiedRect().height());
}

void Scaler::SetDeltaSize(const DeltaSize &delta_size) {
  shifter_->SetDeltaSize(delta_size);
  stretcher_->SetDeltaSize(delta_size);
}

void Scaler::SetDeltaSize(DeltaSize &&delta_size) {
  shifter_->SetDeltaSize(std::move(delta_size));
  stretcher_->SetDeltaSize(std::move(delta_size));
}

void Scaler::SetScalingFactor(const AxesRatio &shift_ratio,
                              const AxesRatio &stretch_ratio) {
  shifter_->SetAxesRatio(shift_ratio);
  stretcher_->SetAxesRatio(stretch_ratio);
}

void Scaler::SetShiftFactor(const AxesRatio &shift_ratio) {
  stretcher_->SetAxesRatio(AxesRatio(0.0, 0.0));
  shifter_->SetAxesRatio(shift_ratio);
}

void Scaler::SetStretchFactor(const AxesRatio &stretch_ratio) {
  shifter_->SetAxesRatio(AxesRatio(0.0, 0.0));
  stretcher_->SetAxesRatio(stretch_ratio);
}

void Scaler::ScaleTo(unsigned int shift_to, unsigned int stretch_to) {
  shifter_->ModifyTo(shift_to);
  stretcher_->ModifyTo(stretch_to);
}

void Scaler::ShiftTo(unsigned int shift_to) { shifter_->ModifyTo(shift_to); }

void Scaler::StretchTo(unsigned int stretch_to) {
  stretcher_->ModifyTo(stretch_to);
}
