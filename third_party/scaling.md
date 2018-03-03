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
  int delta_width = width() - initial_width_;
  int delta_height = height() - initial_height_;

  scaler_.SetDeltaSize(DeltaSize(delta_width, delta_height));
  scaler_.ComputeModification(initial_label_geometry_);

  label_->setGeometry(scaler_.GetModifiedRect());
}

```
As you can see,  in method SetScalingFactor we set shift factor by all axes as 0.0, that mean scaling will be only as stretching. The stretching set up as 1.0 for both axes ( X and Y ) will be stretch label as much as parent size. This parameter can be taken as percentage evaluation.

When scaling factor is set, we need to define in which side label will be stretched. The ScaleTo method help us to do this. The first parameter is for geometry shifting and the second for stretching.

In resize event we compute delta parameters as current widget width or height minus the initial size. After that we pass delta size into scaler and compute modified rect.

After computation we may get modified rect.
And as the result we can do this:

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/scaling_example.gif'>

Let's change scaling factor and set only shifting:

```C++

// ctor
{
scaler_.SetScalingFactor(AxesRatio(0.0, 0.0), AxesRatio(1.0, 1.0));
}

```
<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/shifting_example.gif'>

### Stretcher and Shifter

Scaler is combiner of two classes Stretcher and Shifter, thus if you want to use only stretching or shifting you are able to use only this class.

#### Stretcher