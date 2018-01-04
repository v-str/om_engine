#ifndef CONVERSION_MAKER_H
#define CONVERSION_MAKER_H

namespace om_composing {

class ConversionMaker {
 public:
  ConversionMaker();
  ConversionMaker(float x_axis_value, float y_axis_value);

  void SetConversionByX(float x_axis_value);
  void SetConversionByY(float y_axis_value);

  float X() const;
  float Y() const;

 private:
  float CheckValue(float axis_value) const;

  static constexpr float kMinValue = 0.0;
  static constexpr float kMaxValue = 3.0;

  float x_axis_value_;
  float y_axis_value_;
};
}

#endif  // CONVERSION_MAKER_H
