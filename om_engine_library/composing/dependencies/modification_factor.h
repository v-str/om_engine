#ifndef MODIFICATION_FACTOR_H
#define MODIFICATION_FACTOR_H

namespace om_composing {

class ModificationFactor {
 public:
  ModificationFactor();
  ModificationFactor(float x_axis_value, float y_axis_value);

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

#endif  // MODIFICATION_FACTOR_H
