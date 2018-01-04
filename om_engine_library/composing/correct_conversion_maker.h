#ifndef CORRECT_CONVERSION_MAKER_H
#define CORRECT_CONVERSION_MAKER_H

namespace om_composing {

class CorrectConversionMaker {
 public:
  CorrectConversionMaker();
  CorrectConversionMaker(float x_axis_value, float y_axis_value);

 private:
  static constexpr float kMinValue = 0.0;
  static constexpr float kMaxValue = 3.0;

  float x_axis_value_;
  float y_axis_value_;
};
}

#endif  // CORRECT_CONVERSION_MAKER_H
