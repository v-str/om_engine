#include <om_td.h>

#include <QLabel>

using namespace om_widgets;

OmTD::OmTD(QWidget* parent, Qt::Orientation labels_orientation)
    : QWidget(parent), labels_orientation_(labels_orientation) {
  time_label_ = new QLabel(this);
  date_label_ = new QLabel(this);
}

OmTD::~OmTD() {}
