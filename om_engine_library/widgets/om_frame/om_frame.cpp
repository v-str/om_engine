#include <om_frame.h>

using namespace om_widgets;
using namespace om_animation;
using namespace geometry_modification;

OmFrame::OmFrame(QWidget *parent, bool is_widget_open)
    : QFrame(parent),
      state_animator_(new StateAnimator(this, is_widget_open)) {}

OmFrame::~OmFrame() {}

void OmFrame::ModifyGeometry(const QRect &initial_geometry,
                             const DeltaSize &delta_size) {
  if (!state_animator_->IsWidgetOpen()) {
    close();
  }
  SetDeltaSize(delta_size);
  ComputeModification(initial_geometry);
  SetCurrentGeometry(Scaler::GetModifiedRect());
}

void OmFrame::SetAnimation(const QEasingCurve &curve,
                           unsigned int animation_duration_msec,
                           unsigned int open_to, unsigned int close_in_to) {
  state_animator_->SetAnimation(curve, animation_duration_msec, open_to,
                                close_in_to);
}

void OmFrame::SetCurrentGeometry(const QRect &widget_geometry) {
  setGeometry(widget_geometry);
  state_animator_->SetCurrentGeometry(widget_geometry);
}

void OmFrame::Close() { state_animator_->Close(); }

void OmFrame::Open() { state_animator_->Open(); }
