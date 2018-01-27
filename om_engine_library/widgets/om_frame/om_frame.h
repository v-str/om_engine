#ifndef OM_FRAME_H
#define OM_FRAME_H

#include <scaler.h>
#include <QFrame>

#include <memory>

class QWidget;

namespace om_animation {
class StateAnimator;
}

namespace om_widgets {
using namespace om_animation;
using namespace geometry_modification;

class OmFrame : public QFrame, public Scaler {
  Q_OBJECT
 public:
  OmFrame(QWidget* parent = nullptr, bool is_widget_open = true);
  ~OmFrame();

 private:
  std::unique_ptr<StateAnimator> state_animator_;
};
}

#endif  // OM_FRAME_H
