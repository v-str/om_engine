#ifndef CAT_P_5000_LABEL_H
#define CAT_P_5000_LABEL_H

#include <QLabel>

namespace client_code {

class CatP5000Label : public QLabel {
  Q_OBJECT
 public:
  CatP5000Label(QLabel* parent = nullptr);
  ~CatP5000Label();
};
}

#endif  // CAT_P_5000_LABEL_H
