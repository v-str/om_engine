// OmTd - om time and date widget for time and date

#ifndef OM_TD_H
#define OM_TD_H

#include <QWidget>

class QLabel;

namespace om_widgets {
class OmTD : public QWidget {
  Q_OBJECT
 public:
  OmTD(QWidget* parent = nullptr,
       Qt::Orientation labels_orientation = Qt::Horizontal);
  ~OmTD();

 private:
  QLabel* time_label_ = nullptr;
  QLabel* date_label_ = nullptr;

  Qt::Orientation labels_orientation_;
};
}

#endif  // OM_TD_H
