# Scaling

Important part of OmEngine library is scaling. Using this module you can easy scale most widgets of Qt library properly.

<font color='red'>Scaler</font>
-------------------------------------

The Scaler combines two simple conceptions - stretching and shifting of widget. Lets look how to use it.

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

#include <test_widget.h>

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
scaler_.SetScalingFactor(AxesRatio(0.15, 0.15), AxesRatio(0.0, 0.0));
}

```
<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/shifting_example.gif'>

<font color='red'>Stretcher and Shifter</font>
----------------------------------------------

Scaler is combiner of two classes Stretcher and Shifter, thus if you want to use only stretching or shifting you are able to use one of this classes.

<font color='red'>Stretcher</font>
----------------------------------

```C++

#include <stretcher.h>

// ctor
}
stretcher_.SetAxesRatio(AxesRatio(1.0, 1.0));
stretcher_.ModifyTo(kRight | kDown);
}

// resize event
{
int delta_width = width() - initial_width_;
int delta_height = height() - initial_height_;

stretcher_.SetDeltaSize(DeltaSize(delta_width, delta_height));
stretcher_.ComputeModification(initial_label_geometry_);

label_->setGeometry(stretcher_.GetModifiedRect()); // Mark this
}

```
In marked line we set geometry of widget like for a examples at the top code snippets.

<font color='red'>Shifter</font>
--------------------------------

```C++

#include <shifter.h>

// ctor
}
shifter_.SetAxesRatio(AxesRatio(0.5, 0.5));
shifter_.ModifyTo(kRight | kDown);
}

// resize event
{
int delta_width = width() - initial_width_;
int delta_height = height() - initial_height_;

shifter_.SetDeltaSize(DeltaSize(delta_width, delta_height));
shifter_.ComputeModification(initial_label_geometry_);

label_->setGeometry(shifter_.GetModifiedRect());
}

```
By the way if you want that your modified widget be at the center of parent widget you must to set shifter like at this example.

<font color='red'>FontSizeGenerator</font>
------------------------------------------

FontSizeGenerator is class that increase or decrease size of font when widget stretched.

Usage:

```C++

#include <font_size_generator.h>
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
FontSizeGenerator* font_generator_ = nullptr;
  
Scaler scaler_;
QRect initial_label_geometry_;

int initial_width_ = 300;
int initial_height_ = 200;
};

```

Note that for generate font size properly you should set initial font in pixels.

```C++

#include <test_widget.h>

#include <QFont>

estWidget::TestWidget(QWidget *parent)
   : QWidget(parent), label_(new QLabel("OmEngine", this)) {
CustomizeTestSet();

QFont font;

font.setPixelSize(15);
label_->setFont(font);

font_generator_ = new FontSizeGenerator(1.6, *label_);

scaler_.SetScalingFactor(AxesRatio(0.0, 0.0), AxesRatio(1.0, 1.0));
scaler_.ScaleTo(kRight | kDown, kRight | kDown);
}

TestWidget::~TestWidget() { delete font_generator_; }

void TestWidget::resizeEvent(QResizeEvent *) {
int delta_width = width() - initial_width_;
int delta_height = height() - initial_height_;

scaler_.SetDeltaSize(DeltaSize(delta_width, delta_height));
scaler_.ComputeModification(initial_label_geometry_);
label_->setGeometry(scaler_.GetModifiedRect());

font_generator_->GenerateFontSize(label_);
}

```

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/font_size_generator.gif'>