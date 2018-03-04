#ifndef AXES_RATIO_H
#define AXES_RATIO_H

namespace scaling {

class AxesRatio {
 public:
  AxesRatio();
  AxesRatio(float x_axis_value, float y_axis_value);

  void SetConversionByX(float x_axis_value);
  void SetConversionByY(float y_axis_value);

  float X() const;
  float Y() const;

 private:
  float CheckValueForCorrectness(float axis_value) const;

  static constexpr float kMinValue = 0.0;
  static constexpr float kMaxValue = 3.0;

  float x_axis_value_;
  float y_axis_value_;
};
}

#endif  // AXES_RATIO_H
