# Widgets

It is simple set of widgets, inherited from of <span style="color:green">Qt</span> library classes and
modified a little.

<br>

Also it include more lower modules of OmEngine library for correct
animation and widget composing or scaling.

Usage: 

```C++

using namespace om_widgets;
using namespace widgets_utility;

{
  ClickButton* button = new ClickButton(widget);
  button->SetOffsetParameters(OffsetDistance(2, 2), kRight | kDown);
}

```