#include <date_label.h>

#include <QDate>

using namespace om_widgets;

DateLabel::DateLabel(QWidget* parent) : AbstractClock(parent) {
  Update();
  InitializeTimer(this);
}

DateLabel::~DateLabel() {}

void DateLabel::Update() { setText(QDate::currentDate().toString("dd.MM.yy")); }
