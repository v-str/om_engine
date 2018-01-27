#include <test_frame.h>

#include <QFont>

#include <test_message.h>
#include <test_widget_setter.h>

using namespace demo_code;

TestFrame::TestFrame(QWidget* parent)
    : QFrame(parent),
      test_label_(new QLabel(this)),
      animator_(new StateAnimator(test_label_, true)),
      open_button_(new ClickButton("Open frame", this)),
      close_button_(new ClickButton("Close frame", this)),
      display_text_button_(new ClickButton("Display text", this)),
      text_animator1_(new TextAnimator(this, 30)) {
  SetTestFrame();
  SetWidgets();
  SetLabel();
  SetAnimation();
  SetConnections();
}

TestFrame::~TestFrame() { delete text_animator1_; }

void TestFrame::DisplayText() { text_animator1_->RunAnimation(test_label_); }

void TestFrame::IsAnimationComplete() {
  TestMessage::WriteTestMessage(
      "test_label_ text animation test by method "
      "complete . . . ");
}

void TestFrame::SetTestFrame() {
  TestWidgetSetter::CustomizeFrame(this, QRect(0, 0, 0, 0));
  resize(500, 300);
}

void TestFrame::SetWidgets() {
  TestWidgetSetter::CustomizeButton(open_button_, QRect(30, 10, 95, 30));
  TestWidgetSetter::CustomizeButton(close_button_, QRect(135, 10, 95, 30));
  TestWidgetSetter::CustomizeButton(display_text_button_,
                                    QRect(240, 10, 95, 30));
}

void TestFrame::SetLabel() {
  TestWidgetSetter::CustomizeLabel(test_label_, QRect(30, 100, 500, 190));
  QFont font = test_label_->font();
  font.setPointSize(20);
  test_label_->setFont(font);
}

void TestFrame::SetAnimation() {
  animator_->SetAnimation(QEasingCurve::OutCirc, 500, kRight, kLeft);
  animator_->SetCurrentGeometry(test_label_->geometry());
  text_animator1_->SetAnimationText("Ordinary Mind is greeting you . . .");
}

void TestFrame::SetConnections() {
  connect(close_button_, SIGNAL(clicked(bool)), animator_, SLOT(Close()));
  connect(open_button_, SIGNAL(clicked(bool)), animator_, SLOT(Open()));
  connect(display_text_button_, SIGNAL(clicked(bool)), SLOT(DisplayText()));
  connect(text_animator1_, SIGNAL(TextAnimationComplete()),
          SLOT(IsAnimationComplete()));
}
