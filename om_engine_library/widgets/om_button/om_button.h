#ifndef OM_BUTTON_H
#define OM_BUTTON_H

#include <memory>

#include <QPushButton>

#include <geometry_composer.h>
#include <om_utility.h>

namespace om_widgets {

using namespace om_utility;
using namespace om_composing;

class OmButton : public QPushButton {
  Q_OBJECT
 public:
  explicit OmButton(QWidget* parent = nullptr);
  OmButton(const QString& button_text, QWidget* parent = nullptr);
  ~OmButton();

  void SetOffsetSide(unsigned int offset_side);
  void SetOffsetDistance(const om_utility::OffsetDistance& offset_distance);

  void SetGeometryComposer(const ModificationFactor& modification_factor,
                           Side modify_to = kRight,
                           TransformationType type = kShifting);

  void SetDeltaSize(const DeltaSize& delta_size);

  void ComposeGeometry(const QRect& initial_widget_geometry);

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  unsigned int offset_side_;
  OffsetDistance offset_distance_;

  std::unique_ptr<GeometryComposer> geometry_composer_;
};
}

#endif  // OM_BUTTON_H
