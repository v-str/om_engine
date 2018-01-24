#ifndef TEXT_ANIMATOR_H
#define TEXT_ANIMATOR_H

#include <stdexcept>

#include <QMetaObject>
#include <QObject>
#include <QScopedPointer>
#include <QString>
#include <QTimer>

#include <writable_matcher.h>
#include <writable_widget.h>

namespace om_animation {
class TextAnimator : public QObject {
  Q_OBJECT
 public:
  TextAnimator(QObject* parent = nullptr, unsigned int animation_delay = 10);
  ~TextAnimator();

  void SetAnimationDelay(unsigned int animation_delay);
  void SetAnimationText(const QString& animation_text);

  template <typename Widget>
  void RunAnimation(Widget* widget);

 private slots:
  void AnimateText();

 signals:
  void TextAnimationComplete();

 private:
  void Reset();
  bool IsStringEnd() const;

  QTimer* timer_ = nullptr;

  QScopedPointer<AbstractWritableWidget> writable_widget_;
  QString animation_text_;
  QString current_text_;
  unsigned int animation_delay_;
  unsigned int symbol_count_ = 0;
};
}

// type erasure idiom
template <typename Widget>
void om_animation::TextAnimator::RunAnimation(Widget* widget) {
  if (WritableMatcher::IsWidgetWritable(widget->metaObject()->className())) {
    writable_widget_.reset(new WritableWidget<Widget>(widget));
    timer_->start(animation_delay_);
  } else {
    throw std::logic_error(
        "incompatible type for text animation, add type to "
        "WritableMatcher class");
  }
}

#endif  // TEXT_ANIMATOR_H
