#ifndef OM_FRAME_H
#define OM_FRAME_H

#include <scaler.h>
#include <QFrame>

#include <memory>

#include <QEasingCurve>
#include <QRect>

#include <state_animator.h>

class QWidget;

namespace om_widgets {
using namespace om_animation;
using namespace scaling;

class OmFrame : public QFrame, public Scaler {
  Q_OBJECT
 public:
  OmFrame(QWidget* parent = nullptr, bool is_widget_open = true);
  ~OmFrame();

  void ModifyGeometry(const QRect& initial_geometry,
                      const DeltaSize& delta_size);

  void SetAnimation(const QEasingCurve& curve = QEasingCurve::OutCirc,
                    unsigned int animation_duration_msec = 500,
                    unsigned int open_to = om_animation::Side::kUp,
                    unsigned int close_in_to = om_animation::Side::kDown);

  void SetCurrentGeometry(const QRect& widget_geometry);

 public slots:
  void Close();
  void Open();

 signals:
  void AnimationComplete();
  void AnimationIncomplete();

 private:
  std::unique_ptr<StateAnimator> state_animator_;
};
}

#endif  // OM_FRAME_H
