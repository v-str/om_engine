# Scaling

Important part of OmEngine library is scaling. Using this module you can easy scale most widgets of Qt library properly.

### Scaler

The Scaler combines two simple conception - stretching and shifting of widget. Lets look to how it use.

Let's suppose that we want to stretch some label when parent widget is resizing.
We need a label instance, scaler instance and parent class.

```C++

#include <QLabel>
#include <QRect>
#include <QWidget>

#include <scaler.h>

using namespace scaling;

class TestWidget : public QWidget {
  Q_OBJECT
 public:
  TestWidget(QWidget* parent = nullptr);
  ~TestWidget();

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void CustomizeTestSet();

  QLabel* label_ = nullptr;

  Scaler scaler_;
  QRect initial_label_geometry_;
};

```