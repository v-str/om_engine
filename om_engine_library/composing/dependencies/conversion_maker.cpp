#include <conversion_maker.h>

using namespace om_composing;

ConversionMaker::ConversionMaker()
    : x_axis_value_(0.0), y_axis_value_(0.0) {}

ConversionMaker::ConversionMaker(
    float x_axis_value, float y_axis_value) {
  x_axis_value_ = CheckValue(x_axis_value);
  y_axis_value_ = CheckValue(y_axis_value);
}

void ConversionMaker::SetConversionByX(
    float x_axis_value) {
  x_axis_value_ = CheckValue(x_axis_value);
}

void ConversionMaker::SetConversionByY(
    float y_axis_value) {
  y_axis_value_ = CheckValue(y_axis_value);
}

float ConversionMaker::X() const { return x_axis_value_; }

float ConversionMaker::Y() const { return y_axis_value_; }

float ConversionMaker::CheckValue(float axis_value) const {
  if (axis_value > kMaxValue) {
    return kMaxValue;
  } else if (axis_value < kMinValue) {
    return kMinValue;
  }
  return axis_value;
}
