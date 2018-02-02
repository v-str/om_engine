#include <font_size_calculator.h>

int FontSizeCalculator::CalculateCurrentFontSize(
    const QSize& current_widget_size,
    const InitialWidgetData& initial_widget_data) {
  initial_widget_data_ = initial_widget_data;

  if (IsCurrentSizeLessThenInitial(current_widget_size)) {
    return initial_widget_data_.InitialWidgetFont().pixelSize();
  } else {
    CalculateDeltaSize(current_widget_size);
    CalculateFontIncrement();
    return CurrentFontSize();
  }
}

void FontSizeCalculator::CalculateDeltaSize(const QSize& current_widget_size) {
  delta_size_.setWidth(current_widget_size.width() -
                       initial_widget_data_.InitialWidgetWidth());
  delta_size_.setHeight(current_widget_size.height() -
                        initial_widget_data_.InitialWidgetHeight());
}

void FontSizeCalculator::CalculateIncrement(int delta_side_size) {
  font_increment_ =
      initial_widget_data_.FontScaleMultiplier() *
      (delta_side_size / initial_widget_data_.InitialWidgetFont().pixelSize());
}

bool FontSizeCalculator::IsCurrentSizeLessThenInitial(
    const QSize& current_widget_size) {
  return current_widget_size.width() <
             initial_widget_data_.InitialWidgetWidth() ||
         current_widget_size.height() <
             initial_widget_data_.InitialWidgetHeight();
}

void FontSizeCalculator::CalculateFontIncrement() {
  if (delta_size_.width() >= delta_size_.height()) {
    CalculateIncrement(delta_size_.width());
  } else {
    CalculateIncrement(delta_size_.height());
  }
}

int FontSizeCalculator::CurrentFontSize() const {
  return initial_widget_data_.InitialWidgetFont().pixelSize() + font_increment_;
}
