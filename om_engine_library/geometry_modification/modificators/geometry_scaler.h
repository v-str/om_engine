#ifndef GEOMETRY_SCALER_H
#define GEOMETRY_SCALER_H

#include <memory>

#include <QRect>
#include <QWidget>

#include <geometry_modifier.h>
#include <om_utility.h>

namespace geometry_modification {
using namespace om_utility;

class GeometryScaler {
 public:
  GeometryScaler(const ModificationFactor& modification_shift_factor,
                 const ModificationFactor& modification_stretch_factor,
                 Side shift_to = kRight, Side stretch_to = kRight);

  void ScaleGeometry(const QRect& initial_widget_geometry, QWidget* widget);

  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  QRect AddRects(const QRect& shifted_geometry,
                 const QRect& stretched_geometry);

  std::unique_ptr<GeometryModifier> shifter_;
  std::unique_ptr<GeometryModifier> stretcher_;
};
}

#endif  // GEOMETRY_SCALER_H
