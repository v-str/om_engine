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

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/animation_state_example.gif'>

### TextAnimator

Let's add on our frame simple label that showing some text when some button clicked. But this text will be represented through TextAnimator.

Declare the pointer to text animator and 2 pointers to the buttons for text animation (start and stop for example).

Also you need to declare 2 public slots for text animation ( as text animator performed in simple methods style)

```C++
#include <text_animator.h>

using namespace om_animation;

class TestWidget : public QWidget{
Q_OBJECT
pubcic:
// ctor
// dtor

public slots:
void RunTextAnimation();
void ResetAnimaiton();

private:
TextAnimator* text_animator_ = nullptr;
QPushButton* show_text_button_ = nullptr;
QPushButton* clear_text_button_ = nullptr;
}
```

At the translation unit in constructor initialization part ( or body ) you should pass to the text animation constructor a parent class and set animation delay ( by default this parameter set to 10 msec ).

In our case the parent is QFrame instance and delay equal 60 msec.

After that you should set the desired text.

In the end set the desired text and bind TextAnimator instance with buttons using Qt connection.


```C++
TestWidget::TestWidget(QWidget * parent) : QWidget(parent), text_animator(new TextAnimator(frame_, 60)) {

text_animator_->SetAnimationText("Hello world!");

connect(show_text_button_, SIGNAL(clicked(bool)), SLOT(RunTextAnimation()));
connect(clear_text_button_, SIGNAL(clicked(bool)), SLOT(ResetAnimaiton()));
}

void TestWidget::RunTextAnimation() { text_animator_->RunAnimation(label_); }

void TestWidget::ResetAnimaiton() {
text_animator_->ResetAnimation();
label_->clear();
}
```

Note that the TextAnimation method ResetAnimation is not erase text of widget, it is just stop the timer and erase internal buffer. You should clear text of chosen widget manualy.
