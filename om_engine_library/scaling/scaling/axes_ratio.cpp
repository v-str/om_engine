#include <axes_ratio.h>

using namespace scaling;

AxesRatio::AxesRatio() : x_axis_value_(0.0), y_axis_value_(0.0) {}

AxesRatio::AxesRatio(float x_axis_value, float y_axis_value) {
  x_axis_value_ = CheckValueForCorrectness(x_axis_value);
  y_axis_value_ = CheckValueForCorrectness(y_axis_value);
}

void AxesRatio::SetConversionByX(float x_axis_value) {
  x_axis_value_ = CheckValueForCorrectness(x_axis_value);
}

void AxesRatio::SetConversionByY(float y_axis_value) {
  y_axis_value_ = CheckValueForCorrectness(y_axis_value);
}

float AxesRatio::X() const { return x_axis_value_; }

float AxesRatio::Y() const { return y_axis_value_; }

float AxesRatio::CheckValueForCorrectness(float axis_value) const {
  if (axis_value > kMaxValue) {
    return kMaxValue;
  } else if (axis_value < kMinValue) {
    return kMinValue;
  }
  return axis_value;
}
