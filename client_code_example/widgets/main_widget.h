#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QFrame>
#include <QPainter>
#include <QPalette>
#include <QPixmap>
#include <QWidget>

#include <abstract_clock.h>
#include <click_button.h>
#include <delta_size.h>
#include <geometry_modifier.h>
#include <main_frame.h>

namespace client_code {

using namespace om_widgets;
using namespace om_animation;
using namespace scaling;

class MainWidget : public QWidget {
  Q_OBJECT
 public:
  explicit MainWidget(QWidget* parent = nullptr);
  ~MainWidget();

 protected:
  void resizeEvent(QResizeEvent*);
  void paintEvent(QPaintEvent*);

 private:
  void SetAppearance();
  void SetWidgets();
  void SetAnimation();
  void SetConnections();
  void ShiftClocks();
  DeltaSize GetDeltaSize();

  ClickButton* button_open_ = nullptr;
  ClickButton* button_close_ = nullptr;
  AbstractClock* time_label_ = nullptr;
  AbstractClock* date_label_ = nullptr;
  MainFrame* main_frame_ = nullptr;
  GeometryModifier* shifter_ = nullptr;

  QPalette palette_;
  QPixmap pixmap_;
};
}

#endif  // MAIN_WIDGET_H
