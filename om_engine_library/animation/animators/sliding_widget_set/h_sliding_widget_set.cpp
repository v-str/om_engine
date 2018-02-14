#include <h_sliding_widget_set.h>

#include <QRect>
#include <QVariant>
#include <QWidget>

using namespace om_animation;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent, bool is_set_open,
                                     SlideDirection slide_direction,
                                     unsigned int distance_btw_widgets_px)
    : AbstractSlidingWidgetSet(parent, is_set_open),
      slide_direction_(slide_direction),
      distance_btw_widgets_px_(distance_btw_widgets_px) {}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::ComposeAnimation() {
  // now need to calculate open and close animation for two variants of sliding
  // direction
  //
  // for kFromLeftToRight:
  //
  if (slide_direction_ == kFromLeftToRight) {
    {
      int init_x_pos = GetWidgetVector()->at(0)->x();
      for (size_t i = 0; i < GetWidgetVector()->size(); ++i) {
        GetCloseGeometryVector()->at(i)->setX(init_x_pos);
        GetCloseGeometryVector()->at(i)->setY(GetWidgetVector()->at(0)->y());
        GetCloseGeometryVector()->at(i)->setWidth(0);
        GetCloseGeometryVector()->at(i)->setHeight(
            GetWidgetVector()->at(0)->height());
      }
    }
    {
      int x_pos = GetWidgetVector()->at(0)->x();
      for (size_t i = 0; i < GetWidgetVector()->size(); ++i) {
        GetOpenGeometryVector()->at(i)->setX(x_pos);
        GetOpenGeometryVector()->at(i)->setY(GetWidgetVector()->at(i)->y());
        GetOpenGeometryVector()->at(i)->setWidth(
            GetWidgetVector()->at(i)->width());
        GetOpenGeometryVector()->at(i)->setHeight(
            GetWidgetVector()->at(i)->height());
        x_pos += GetWidgetVector()->at(i)->width() + distance_btw_widgets_px_;
      }
    }
  }
}
