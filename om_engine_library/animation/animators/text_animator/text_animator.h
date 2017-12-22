#ifndef TEXT_ANIMATOR_H
#define TEXT_ANIMATOR_H

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
  explicit TextAnimator(QObject* parent = nullptr,
                        unsigned int animation_delay = 10);
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

  AbstractWritableWidget* writable_widget_ = nullptr;

  QTimer* timer_ = nullptr;
  QString animation_text_;
  QString current_text_;
  unsigned int animation_delay_;
  unsigned int symbol_count_ = 0;
};
}  // namespace om_animation

template <typename Widget>
void om_animation::TextAnimator::RunAnimation(Widget* widget) {
  if (WritableMatcher::IsWidgetWritable(widget->metaObject()->className())) {
    if (writable_widget_) {
      delete writable_widget_;
    }
    writable_widget_ = new WritableWidget<Widget>(widget);
    timer_->start(animation_delay_);
  } else {
    throw std::logic_error(
        "incompatible type for text animation, add type to "
        "WritableMatcher class");
  }
}

#endif  // TEXT_ANIMATOR_H
