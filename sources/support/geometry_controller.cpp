#include <geometry_controller.h>

using namespace demo_code;

GeometryComposer GeometryController::composer_(ModificationFactor(1.0, 0.0));

GeometryScaler GeometryController::scaler_(ModificationFactor(0.1, 0.1),
                                           ModificationFactor(0.1, 0.1));

void GeometryController::ComposeGeometry(const QRect &initial_widget_geometry,
                                         QWidget *widget) {
  composer_.ComposeGeometry(initial_widget_geometry, widget);
}

void GeometryController::ScaleGeometry(const QRect &initial_widget_geometry,
                                       QWidget *widget) {
  scaler_.ScaleGeometry(initial_widget_geometry, widget);
}

void GeometryController::SetDeltaSize(const DeltaSize &delta_size) {
  composer_.SetDeltaSize(delta_size);
  scaler_.SetDeltaSize(delta_size);
}
