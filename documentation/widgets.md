# Widgets

It is simple set of widgets, inherited from of <span style="color:green">Qt</span> library classes and
modified a little.

Also it include more lower modules of OmEngine library for correct
animation and widget composing or scaling.

<font color='red'>ClickButton</font>
------------------------------------

It is a QPushButton but it may offset(or not) when cursor is entry of button
space. You can configure the side of offset and the size of offset (pixels).

Usage: 

```C++

#include <click_button.h>

using namespace om_widgets;
using namespace widgets_utility;

{
  ClickButton* button = new ClickButton(widget);
  button->SetOffsetParameters(OffsetDistance(2, 2), kRight | kDown);
}

```

Result (colorized for convenience):

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/click_button_example.gif'>

<font color='red'>Clocks</font>
--------------------------------

Widgets, inherited from QLabel and implement only one thing - demonstration
of time or date after those initialization. It is mean, once you define this
widgets - they'll be change time and date immediately.

Usage:

```C++

#include <date_label.h>
#include <time_label.h> 

using namespace om_widgets;

{
  TimeLabel* time_label(new TimeLabel(widget));
  DateLabel* date_label(new DateLabel(widget));
}

```

Result (colorized for convenience):

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/time_and_date_example.gif'>

<font color='red'>OmFrame</font>
--------------------------------

OmFrame is main class of this library. It is include most of library details and perform:

1. Opening-Closing animation
2. Selfscaling depending of parent widget size

Usage:

```C++

#include <om_frame>

using namespace om_widgets;

TestWidget::TestWidget(QWidget * parent) : QWidget(parent) 
{

//... skip another details

om_frame = new OmFrame(this, true);								//	1
om_frame->SetCurrentGeometry(InitialFrameGeometry());						//	2
om_frame->SetStretchFactor(scaling::AxesRatio(1.0, 1.0));					//	3
om_frame->StretchTo(scaling::kRight | scaling::kDown);						//	4

connect(open_button_, SIGNAL(clicked(bool)), om_frame_, SLOT(Open()));
connect(close_button_, SIGNAL(clicked(bool)), om_frame_, SLOT(Close()));

}

TestWidget::resizeEvent(QResizeEvent*){

  int delta_width = width() - initial_width_;
  int delta_height = height() - initial_height_;

  om_frame->ModifyGeometry(InitialFrameGeometry(), 
						DeltaSize(delta_width, delta_height));		//	5

}

```

Description:

In line 1 we initialize pointer and pass into constructor 2 parameters - parent and frame state. The frame state may be either open or closed. ( By default, the second parameter is_widget_open set to 'true', but for example it was set explicit ).

Unlike the simple QFrame class you must set geometry using SetCurrentGeometry() method ( line 2 ), because OmFrame sets different parameters in this method 'under the hood'.

In the line 3 we set the stretch factor of our OmFrame instance. For example, if parent widget was stretched on 20 pixels by axes X and Y then om_frame will be stretched by the same size.

The next step is setting stretch direction (line 4). By default, you may stretch or shift OmFrame instance to the:

- Left
- Right
- Up
- Down

or combine several direction.

Further we connect buttons with slots that opens and closes our frame.

In line 5 we setting up resizing method of OmFrame that named ModifyGeometry() in which we pass two parameters - initial geometry ( in this example it is method InitialFrameGeometry() ) and object of DeltaSize that storing deltas of parent widget.

As OmFrame inherited from Scaler class, for more details , please read  [scaling](https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/documentation/scaling.md)  documentation part.

Result (colorized for convenience):

<img src='https://github.com/OrdinaryMind/om_engine/blob/om_engine_v_1_0/examples/om_frame_example.gif'>