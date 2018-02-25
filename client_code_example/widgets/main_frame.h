#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <om_frame.h>

#include <main_label.h>
#include <main_label_text_display.h>
#include <title_button_frame.h>
#include <work_button_frame.h>

class QWidget;

namespace client_code {

using namespace om_widgets;
using namespace om_animation;

class MainFrame : public OmFrame {
  Q_OBJECT
 public:
  MainFrame(QWidget* parent = nullptr, bool is_widget_open = true);
  ~MainFrame();

  void ModifyGeometry(const QRect& initial_geometry,
                      const DeltaSize& delta_size) override;

 private:
  void SetWidgets();
  void SetConnections();

  TitleButtonFrame* title_frame_ = nullptr;
  WorkButtonFrame* work_frame_ = nullptr;
  MainLabel* main_label_ = nullptr;
  MainLabelTextDisplay* main_label_text_setter_ = nullptr;
};
}

#endif  // MAIN_FRAME_H
