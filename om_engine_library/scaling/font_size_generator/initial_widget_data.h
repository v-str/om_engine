#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

#include <QFont>

namespace scaling {

struct InitialWidgetData {
  void SetFontScaleMultiplier(double font_scale_multiplier);
  void SetInitialWidgetWidth(int initial_widget_width);
  void SetInitialWidgetHeight(int initial_widget_height);
  void SetInitialWidgetFont(const QFont& font);

  double FontScaleMultiplier() const;
  int InitialWidgetWidth() const;
  int InitialWidgetHeight() const;
  QFont InitialWidgetFont() const;

 private:
  bool IsFontScaleMultiplierNegative(double value);

  double font_scale_multiplier_ = 0.0;
  int initial_widget_width_ = 0;
  int initial_widget_height_ = 0;
  QFont initial_widget_font_;
};
}
#endif  // INITIAL_DATA_H
