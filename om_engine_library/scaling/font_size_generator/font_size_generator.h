#ifndef FONT_SIZE_GENERATOR_H
#define FONT_SIZE_GENERATOR_H

#include <QFont>
#include <QSize>
#include <QWidget>

#include <font_size_calculator.h>
#include <initial_widget_data.h>

namespace scaling {

class FontSizeGenerator {
 public:
  FontSizeGenerator(double font_scale_multiplier, const QWidget& widget);

  void GenerateFontSize(QWidget* widget) throw(std::logic_error);

  QFont GetGeneratedFont() const;

 private:
  void CaptureWidgetParameters(const QWidget& widget);
  void AssignInitialFont(QWidget* widget);
  void CalculateFontSize(QWidget* widget);

  bool IsWidgetSidesSizeEqualInitial() const;

  QSize currect_widget_size_;
  QFont generated_font_;

  InitialWidgetData initial_widget_data_;
  FontSizeCalculator font_size_calculator_;
};
}
#endif  // FONT_SIZE_GENERATOR_H
