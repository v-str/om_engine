# Animation

### StateAnimator

Is a class that can perform animation related with widget opening or closing. 

Usage:

Let's place on the QWidget the QFrame instance and animate it with StateAnimator.

```C++

#include <QFrame>
#include <QPushButton>
#include <QWidget>

#include <state_animator.h>

using namespace om_animation;

class TestWidget : public QWidget {
  Q_OBJECT
 public:
  TestWidget(QWidget* parent = nullptr);
  ~TestWidget();

 private:
  void CustomizeTestSet();

  QFrame* frame_ = nullptr;
  QPushButton* button_open_ = nullptr;
  QPushButton* button_close_ = nullptr;

  StateAnimator* state_animator_ = nullptr;
};

```

```C++

#include <QFont>
#include <QRect>

TestWidget::TestWidget(QWidget *parent)
    : QWidget(parent),
      frame_(new QFrame(this)),
      button_open_(new QPushButton("Open", this)),
      button_close_(new QPushButton("Close", this)),
      state_animator_(new StateAnimator(frame_, false)) {		// 1
  CustomizeTestSet();

  state_animator_->SetCurrentGeometry(frame_->geometry());		// 2

  connect(button_open_, SIGNAL(clicked(bool)), state_animator_, SLOT(Open()));
  connect(button_close_, SIGNAL(clicked(bool)), state_animator_, SLOT(Close()));
}

```

Line 1: While initializing StateAnimator instance we pass into constructor 2 parameters:

- object for animation
- state of object for animation, closed or opened ( true - opened, false - closed )

Line 2: For the properly animation work you should set current geometry of animated widget ( it is very convenient to use in resize event )

That's all. By default animation performed with next parameters:

- duration - 500 msec
- animation curve - QEasingCurve::OutCirc
- widget will be open to up(kUp) and closed to down(kDown).

But if you want to define another animation behavior you should use SetAnimation method of StateAnimator instance.