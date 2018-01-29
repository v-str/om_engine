#include <test_geometries.h>

using namespace demo_code;

QRect demo_code::MainWidgetGeometry() { return QRect(100, 100, 600, 400); }

QRect demo_code::InheritorFrameGeometry() { return QRect(20, 70, 560, 320); }

QRect demo_code::OpenButtonGeometry() { return QRect(20, 10, 70, 30); }

QRect demo_code::CloseButtonGeometry() { return QRect(100, 10, 70, 30); }

QRect demo_code::TimeLabelGeometry() { return QRect(365, 10, 100, 30); }

QRect demo_code::DateLabelGeometry() { return QRect(480, 10, 100, 30); }
