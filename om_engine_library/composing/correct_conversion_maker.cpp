#include <correct_conversion_maker.h>

om_composing::CorrectConversionMaker::CorrectConversionMaker()
    : x_axis_value_(0.0), y_axis_value_(0.0) {}

om_composing::CorrectConversionMaker::CorrectConversionMaker(
    float x_axis_value, float y_axis_value) {
  x_axis_value_ = x_axis_value;
  y_axis_value_ = y_axis_value;
}
