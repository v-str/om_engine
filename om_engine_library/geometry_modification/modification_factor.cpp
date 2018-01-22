#include <modification_factor.h>

using namespace geometry_modification;

ModificationFactor::ModificationFactor()
    : x_axis_value_(0.0), y_axis_value_(0.0) {}

ModificationFactor::ModificationFactor(float x_axis_value, float y_axis_value) {
  x_axis_value_ = CheckValueForCorrectness(x_axis_value);
  y_axis_value_ = CheckValueForCorrectness(y_axis_value);
}

void ModificationFactor::SetConversionByX(float x_axis_value) {
  x_axis_value_ = CheckValueForCorrectness(x_axis_value);
}

void ModificationFactor::SetConversionByY(float y_axis_value) {
  y_axis_value_ = CheckValueForCorrectness(y_axis_value);
}

float ModificationFactor::X() const { return x_axis_value_; }

float ModificationFactor::Y() const { return y_axis_value_; }

float ModificationFactor::CheckValueForCorrectness(float axis_value) const {
  if (axis_value > kMaxValue) {
    return kMaxValue;
  } else if (axis_value < kMinValue) {
    return kMinValue;
  }
  return axis_value;
}
