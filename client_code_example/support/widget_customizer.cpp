#include <widget_customizer.h>

#include <axes_ratio.h>
#include <offset_distance.h>
#include <widgets_utility.h>

using namespace client_code;
using namespace om_widgets;
using namespace widgets_utility;

void WidgetCustomizer::CustomizeButton(ClickButton* button,
                                       const QRect& current_geometry) {
  button->setStyleSheet(
      "QPushButton{"
      "background-color: rgba(0, 0, 0, 90%);"
      "color: #00CC00;"
      "border: 2px solid #00CC00;"
      "border-radius: 5px;"
      "}"
      "QPushButton:hover:pressed { "
      "border: 2px solid red;"
      "color: red; }");
  button->setWindowOpacity(0.5);
  button->setGeometry(current_geometry);
  button->SetOffsetParameters(OffsetDistance(2, 2), Side::kRight | Side::kDown);
}

void WidgetCustomizer::CustomizeFrame(QFrame* frame,
                                      const QRect& current_geometry) {
  frame->setStyleSheet(
      "QFrame{"
      "background: rgba(0, 0, 0, 60%);"
      "color: #00CC00;"
      "border: 2px solid #00CC00;"
      "border-radius: 5px;"
      "}");
  frame->setWindowOpacity(0.5);
  frame->setGeometry(current_geometry);
}

void WidgetCustomizer::CustomizeLabel(QLabel* label, const QRect& geometry) {
  label->setStyleSheet(
      "QLabel{"
      "background-color: rgba(0, 0, 0, 60%);"
      "border: 2px solid #00CC00;"
      "border-radius: 5px;"
      "color: #00CC00;"
      "}");
  label->setGeometry(geometry);
  label->setAlignment(Qt::AlignCenter);
  label->setWordWrap(true);
}

void WidgetCustomizer::CustomizeTestLabel(QLabel* test_label,
                                          const QRect initial_geometry) {
  test_label->setStyleSheet(
      "QLabel{"
      "background-color: rgba(0, 0, 0, 60%);"
      "border: 2px solid #00CC00;"
      "border-radius: 5px;"
      "color: #009999;"
      "}");
  test_label->setGeometry(initial_geometry);
  test_label->setAlignment(Qt::AlignLeft);
  test_label->setWordWrap(true);
  QFont font = test_label->font();
  font.setPixelSize(20);
  font.setFamily("FreeMono");
  test_label->setFont(font);
}

QString WidgetCustomizer::GetAnimationText() {
  QString text =
      "Spaceship cargo terminal A213:\n\n"
      "Explosive class: A1\n"
      "Scanning power: 75%\n"
      "Cargo stream speed: 10pt\n"
      "Oxygen independence level: 10\n"
      "Main gate status: NEED CHECK\n";

  return text;
}
