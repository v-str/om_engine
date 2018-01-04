#include <correct_conversion_maker.h>

om_composing::CorrectConversionMaker::CorrectConversionMaker()
    : x_axis_value_(0.0), y_axis_value_(0.0) {}

om_composing::CorrectConversionMaker::CorrectConversionMaker(
    float x_axis_value, float y_axis_value) {
  x_axis_value_ = CheckValue(x_axis_value);
  y_axis_value_ = CheckValue(y_axis_value);
}

void om_composing::CorrectConversionMaker::SetConversionByX(
    float x_axis_value) {
  x_axis_value_ = CheckValue(x_axis_value);
}

void om_composing::CorrectConversionMaker::SetConversionByY(
    float y_axis_value) {
  y_axis_value_ = CheckValue(y_axis_value);
}

float om_composing::CorrectConversionMaker::X() const { return x_axis_value_; }

float om_composing::CorrectConversionMaker::Y() const { return y_axis_value_; }

float om_composing::CorrectConversionMaker::CheckValue(float axis_value) const {
  if (axis_value > kMaxValue) {
    return kMaxValue;
  } else if (axis_value < kMinValue) {
    return kMinValue;
  }
  return axis_value;
}
