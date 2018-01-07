#include <geometry_controller.h>


using namespace demo_code;

GeometryComposer GeometryController::shifter_(ModificationFactor(1.0, 0.0));
GeometryComposer GeometryController::stretcher_(ModificationFactor(1.0, 1.0),
                                                kRight | kDown, kStretching);

GeometryScaler GeometryController::scaler_(ModificationFactor(0.1, 0.1),
                                           ModificationFactor(0.1, 0.1));

void GeometryController::ShiftGeometry(const QRect &initial_widget_geometry,
                                       QWidget *widget) {
  shifter_.ComposeGeometry(initial_widget_geometry, widget);
}

void GeometryController::StretchGeometry(const QRect &initial_widget_geometry,
                                         QWidget *widget) {
  stretcher_.ComposeGeometry(initial_widget_geometry, widget);
}

void GeometryController::ScaleGeometry(const QRect &initial_widget_geometry,
                                       QWidget *widget) {
  scaler_.ScaleGeometry(initial_widget_geometry, widget);
}

void GeometryController::SetDeltaSize(const DeltaSize &delta_size) {
  shifter_.SetDeltaSize(delta_size);
  scaler_.SetDeltaSize(delta_size);
  stretcher_.SetDeltaSize(delta_size);
}
