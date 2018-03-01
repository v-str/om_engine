# Scaling

Important part of OmEngine library is scaling. Using this module you can easy scale most widgets of Qt library properly.

### Scaler

The Scaler combines two simple conception - stretching and shifting of widget. Lets look how to use it.

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

In translation unit we:
- initializing label
- set scaler parameters

```C++

#include <test.h>

#include <QDebug>

TestWidget::TestWidget(QWidget *parent)
    : QWidget(parent), label_(new QLabel("OmEngine", this)) {
  CustomizeTestSet();

  scaler_.SetScalingFactor(AxesRatio(0.0, 0.0), AxesRatio(1.0, 1.0));
  scaler_.ScaleTo(kRight, kRight | kDown);
}

TestWidget::~TestWidget() {}

void TestWidget::resizeEvent(QResizeEvent *) {
  int delta_width = width() - 300;
  int delta_height = height() - 200;

  scaler_.SetDeltaSize(DeltaSize(delta_width, delta_height));
  scaler_.ComputeModification(initial_label_geometry_);
  label_->setGeometry(scaler_.GetModifiedRect());
}

```