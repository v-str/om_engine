# Widgets

It is simple set of widgets, inherited from of <span style="color:green">Qt</span> library classes and
modified a little.

<br>

Also it include more lower modules of OmEngine library for correct
animation and widget composing or scaling.

### - ClickButton

It is a QPushButton but it may offset(or not) when cursor is entry of button
space. You can configure the side of offset and the size of offset.

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

### -Clocks

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















