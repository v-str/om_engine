#include <conversion_maker.h>

om_composing::ConversionMaker::ConversionMaker()
    : x_axis_value_(0.0), y_axis_value_(0.0) {}

om_composing::ConversionMaker::ConversionMaker(
    float x_axis_value, float y_axis_value) {
  x_axis_value_ = CheckValue(x_axis_value);
  y_axis_value_ = CheckValue(y_axis_value);
}

void om_composing::ConversionMaker::SetConversionByX(
    float x_axis_value) {
  x_axis_value_ = CheckValue(x_axis_value);
}

void om_composing::ConversionMaker::SetConversionByY(
    float y_axis_value) {
  y_axis_value_ = CheckValue(y_axis_value);
}

float om_composing::ConversionMaker::X() const { return x_axis_value_; }

float om_composing::ConversionMaker::Y() const { return y_axis_value_; }

float om_composing::ConversionMaker::CheckValue(float axis_value) const {
  if (axis_value > kMaxValue) {
    return kMaxValue;
  } else if (axis_value < kMinValue) {
    return kMinValue;
  }
  return axis_value;
}
