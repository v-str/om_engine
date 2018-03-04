#ifndef TEXT_ANIMATOR_H
#define TEXT_ANIMATOR_H

#include <memory>
#include <stdexcept>

#include <QMetaObject>
#include <QObject>
#include <QString>
#include <QTimer>

#include <writable_matcher.h>
#include <writable_widget.h>

namespace om_animation {
class TextAnimator : public QObject {
  Q_OBJECT
 public:
  TextAnimator(QObject* parent = nullptr,
               unsigned int animation_delay_msec = 10);
  ~TextAnimator();

  void SetAnimationDelay(unsigned int animation_delay_msec);
  void SetAnimationText(const QString& animation_text);

  template <typename Widget>
  void RunAnimation(Widget* widget);

  void ResetAnimation();

 signals:
  void TextAnimationComplete();

 private slots:
  void AnimateText();

 private:
  bool IsStringEnd() const;

  QTimer* timer_ = nullptr;

  std::unique_ptr<AbstractWritableWidget> writable_widget_;
  QString animation_text_;
  QString current_text_;
  unsigned int animation_delay_msec_;
  unsigned int symbol_count_ = 0;
};
}

// type erasure idiom
template <typename Widget>
void om_animation::TextAnimator::RunAnimation(Widget* widget) {
  ResetAnimation();
  if (!writable_widget_.get()) {
    writable_widget_ = std::move(std::unique_ptr<AbstractWritableWidget>(
        new WritableWidget<Widget>(widget)));
  }
  if (WritableMatcher::IsWidgetWritable(widget->metaObject()->className())) {
    timer_->start(animation_delay_msec_);
  } else {
    throw std::logic_error(
        "incompatible type for text animation, add type to "
        "WritableMatcher class");
  }
}

#endif  // TEXT_ANIMATOR_H
