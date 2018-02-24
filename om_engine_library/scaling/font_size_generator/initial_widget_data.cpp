#include <initial_widget_data.h>

using namespace scaling;

void InitialWidgetData::SetFontScaleMultiplier(double font_scale_multiplier) {
  if (IsFontScaleMultiplierNegative(font_scale_multiplier)) {
    font_scale_multiplier_ = 0.0;
  } else {
    font_scale_multiplier_ = font_scale_multiplier;
  }
}

void InitialWidgetData::SetInitialWidgetWidth(int initial_widget_width) {
  initial_widget_width_ = initial_widget_width;
}

void InitialWidgetData::SetInitialWidgetHeight(int initial_widget_height) {
  initial_widget_height_ = initial_widget_height;
}

void InitialWidgetData::SetInitialWidgetFont(const QFont& font) {
  initial_widget_font_ = font;
}

double InitialWidgetData::FontScaleMultiplier() const {
  return font_scale_multiplier_;
}

int InitialWidgetData::InitialWidgetWidth() const {
  return initial_widget_width_;
}

int InitialWidgetData::InitialWidgetHeight() const {
  return initial_widget_height_;
}

QFont InitialWidgetData::InitialWidgetFont() const {
  return initial_widget_font_;
}

bool InitialWidgetData::IsFontScaleMultiplierNegative(double value) {
  return value < 0.0;
}
