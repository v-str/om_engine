#include <om_frame.h>

#include <state_animator.h>

using namespace om_widgets;
using namespace om_animation;
using namespace geometry_modification;

OmFrame::OmFrame(QWidget *parent, bool is_widget_open)
    : QFrame(parent),
      state_animator_(new StateAnimator(this, is_widget_open)) {}

OmFrame::~OmFrame() {}
