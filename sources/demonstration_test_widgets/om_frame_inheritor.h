#ifndef OM_FRAME_INHERITOR_H
#define OM_FRAME_INHERITOR_H

#include <om_frame.h>

class QWidget;

namespace om_widgets {
class OmFrameInheritor : public OmFrame {
  Q_OBJECT
 public:
  OmFrameInheritor(QWidget* parent = nullptr, bool is_widget_open = true);
  ~OmFrameInheritor();

 private:
};
}

#endif  // OM_FRAME_INHERITOR_H
