#ifndef MAIN_LABEL_H
#define MAIN_LABEL_H

#include <QLabel>

#include <font_size_generator.h>
#include <scaler.h>
#include <state_animator.h>
#include <text_animator.h>

namespace client_code {

// using namespace om_widgets;
using namespace om_animation;
using namespace scaling;

class MainLabel : public QLabel {
  Q_OBJECT
 public:
  MainLabel(QWidget* parent = nullptr);
  ~MainLabel();

  void ScaleMainLabel(const DeltaSize& delta_size);

 public slots:
  void Open();
  void Close();
  void DisplayText();
  void Clear();

 private:
  void SetLabel();

  StateAnimator* main_label_animator_ = nullptr;
  FontSizeGenerator* font_size_generator_ = nullptr;
  Scaler* main_label_scaler_ = nullptr;
  TextAnimator* text_animator_ = nullptr;

  static const unsigned int text_animation_delay_msec_ = 10;
};
}

#endif  // MAIN_LABEL_H
