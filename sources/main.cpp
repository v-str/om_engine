#include <QApplication>

#include <QFrame>
#include <QLabel>
#include <QObject>
#include <QWidget>

#include <om_button.h>
#include <widget_animator.h>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  QWidget main_widget;
  main_widget.setGeometry(300, 300, 600, 400);

  om_widgets::OmButton* button_open =
      new om_widgets::OmButton("Open!", &main_widget);
  button_open->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  button_open->SetOffsetSide(om_utility::Side::kRight |
                             om_utility::Side::kDown);

  om_widgets::OmButton* button_close =
      new om_widgets::OmButton("Close!", &main_widget);
  button_close->SetOffsetDistance(om_utility::OffsetDistance(2, 2));
  button_close->SetOffsetSide(om_utility::Side::kRight |
                              om_utility::Side::kDown);

  button_open->setGeometry(20, 20, 100, 50);
  button_close->setGeometry(140, 20, 100, 50);

  QFrame* animation_frame = new QFrame(&main_widget);
  animation_frame->setGeometry(20, 100, 560, 250);
  animation_frame->setStyleSheet(
      "QFrame{"
      "background: black;"
      "}");

  QLabel* label = new QLabel("Animation Test", animation_frame);
  label->setGeometry(20, 20, 520, 210);
  label->setAlignment(Qt::AlignCenter);
  label->setStyleSheet(
      "QLabel{"
      "border: 1px solid green;"
      "color: green;"
      "}");

  om_animation::WidgetAnimator close_widget_animator(animation_frame);
  close_widget_animator.SetAnimation(om_utility::WidgetAnimationType::kClose,
                                     QEasingCurve::OutCirc, 500,
                                     om_utility::kLeft | om_utility::kDown);
  close_widget_animator.SetCurrentGeometry(animation_frame->geometry());

  om_animation::WidgetAnimator open_widget_animator(animation_frame);
  open_widget_animator.SetAnimation(om_utility::WidgetAnimationType::kOpen,
                                    QEasingCurve::OutCirc, 500,
                                    om_utility::kRight | om_utility::kUp);
  open_widget_animator.SetCurrentGeometry(animation_frame->geometry());

  QObject::connect(button_close, SIGNAL(clicked(bool)), &close_widget_animator,
                   SLOT(Close()));
  QObject::connect(button_open, SIGNAL(clicked(bool)), &open_widget_animator,
                   SLOT(Open()));

  main_widget.show();

  return app.exec();
}
