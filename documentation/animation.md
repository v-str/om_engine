# Animation

<font color='red'>StateAnimator</font>
-------------------------------------

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

<font color='red'>TextAnimator</font>
-------------------------------------

Let's add on our frame simple label that showing some text when some button clicked. But this text will be represented through TextAnimator.

Declare the pointer to text animator and 2 pointers to the buttons for text animation (start and stop for example).

Also you need to declare 2 public slots for text animation ( as text animator performed in simple methods style)

```C++
#include <text_animator.h>

using namespace om_animation;

class TestWidget : public QWidget{
Q_OBJECT
public:
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

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/text_animator_example.gif'>

<font color='red'>LinearAnimationGroup</font>
---------------------------------------------

Using LinearAnimationGroup class you can animate groups of widget in horizontal or vertical position. If you want animate widget in custom order you should make class that inherited from LinearAnimationGroup with redefined ComposeAnimation() method.

Let's consider 2 cases: vertical group animation (from up to down) and horizontal group animation (from left to right).

For convenience let's create a two vectors that stores a set of buttons. After that we add each button to LinearGroupAnimation instance.

```C++
#include <linear_animation_group.h>

using namespace om_animation;

class TestWidget : public QWidget {
Q_OBJECT
public:
TestWidget(QWidget* parent = nullptr);
~TestWidget();

private:
void CustomizeTestSet();
void SetVectors();
void CustomizeButton(QPushButton* button);
void FillAnimaitonGroup(QVector<QPushButton*>* vector,
                          LinearAnimationGroup* group);

QPushButton* section_1_ = nullptr;
QPushButton* section_2_ = nullptr;

LinearAnimationGroup* v_group_ = nullptr;
LinearAnimationGroup* h_group_ = nullptr;

QVector<QPushButton*> v_animation_vector_;
QVector<QPushButton*> h_animation_vector_;
};
```
I am omit buttons initialization procedure and vectors filling so you should do it yourself.
In constructor of main widget we perform buttons ( that will be open out button groups ) and linear groups initialization. Note that for initialization linear groups we use different classes - H and VLinearAnimationGroup accorgdingly.

```C++
TestWidget::TestWidget(QWidget *parent)
    : QWidget(parent),
      section_1_(new QPushButton("Section 1", this)),
      section_2_(new QPushButton("Section 2", this)),
      h_group_(new HLinearAnimationGroup(
          this, false, HLinearAnimationGroup::kFromLeftToRight, 10)),
      v_group_(new VLinearAnimationGroup(
          this, false, VLinearAnimationGroup::kFromDownToUp, 10)) {
  CustomizeTestSet();

  SetVectors();

  FillAnimaitonGroup(&h_animation_vector_, h_group_);
  h_group_->SetAnimationProperties(500, QEasingCurve::OutQuad);

  FillAnimaitonGroup(&v_animation_vector_, v_group_);
  v_group_->SetAnimationProperties(500, QEasingCurve::OutQuad);

  connect(section_1_, SIGNAL(clicked(bool)), h_group_,
          SLOT(PerformAnimation()));
  connect(section_2_, SIGNAL(clicked(bool)), v_group_,
          SLOT(PerformAnimation()));
}
```
```C++
void TestWidget::FillAnimaitonGroup(QVector<QPushButton *> *vector,
                                    LinearAnimationGroup *group) {
  for (size_t i = 0; i < vector->size(); ++i) {
    group->Add(vector->at(i));
  }
}
```

While initialization we pass into animation group constructor the next params:

1) Parent

2) Group state ( widgets can be opened ( true ) or closed ( false )

3) Enumeration variable that describes how widgets will be animated

4) Distance between widgets in pixels

In constructor body we add every widget that we want to animate in V/HLinearAnimation group instance. For this task we use FillAnimaitonGroup method that simply iterate the vector and adds each of them.

After that we set animation properties. First parameter - animation time and second - animation curve.

That's all. And do not forget connect animation groups with buttons for opening widget group using PerfromAnimation slot.

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/animation_group_example.gif'>

