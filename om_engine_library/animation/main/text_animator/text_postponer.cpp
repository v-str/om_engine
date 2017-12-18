#include <text_postponer.h>

TextPostponer::TextPostponer(QObject* parent,
                             unsigned int interval_postpone_msec)
    : QObject(parent),
      interval_postpone_msec_(interval_postpone_msec),
      timer_(new QTimer(parent)) {
  connect(timer_, SIGNAL(timeout()), SLOT(Run()));
}

TextPostponer::~TextPostponer() {}

void TextPostponer::RunTextPosponing(QLabel* postpone_label) {
  postpone_label_ = postpone_label;
  timer_->start(interval_postpone_msec_);
}

void TextPostponer::ResetIntervalPostpone(unsigned int interval_postpone_msec) {
  interval_postpone_msec_ = interval_postpone_msec;
}

void TextPostponer::SetPostponeText(const QString& postpone_text) {
  postpone_text_ = postpone_text;
}

void TextPostponer::Run() {
  Reset();
  SetCurrentText();
}

void TextPostponer::Reset() {
  postpone_text_.clear();
  current_text_.clear();
  symbol_count_ = 0;
}

void TextPostponer::SetCurrentText() {
  current_text_ += postpone_text_[symbol_count_];
  postpone_label_->setText(current_text_);
  if (IsStringEnd()) {
    timer_->stop();
  }
  ++symbol_count_;
}

bool TextPostponer::IsStringEnd() const {
  return symbol_count_ == (postpone_text_.size() - 1);
}
