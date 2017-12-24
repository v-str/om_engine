#include <om_td.h>

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

using namespace om_widgets;

OmTD::OmTD(QWidget* parent, Qt::Orientation labels_orientation)
    : QWidget(parent),
      labels_orientation_(labels_orientation),
      time_label_(new QLabel(this)),
      date_label_(new QLabel(this)) {
  InitializeLayout();
}

OmTD::~OmTD() {}

void OmTD::InitializeLayout() {
  if (labels_orientation_ == Qt::Horizontal) {
    box_layout_ = new QHBoxLayout(this);
  } else if (labels_orientation_ == Qt::Vertical) {
    box_layout_ = new QVBoxLayout(this);
  }
}
