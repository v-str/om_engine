#ifndef TEXT_ANIMATOR_H
#define TEXT_ANIMATOR_H

#include <stdexcept>

#include <QMetaObject>
#include <QObject>
#include <QString>
#include <QTimer>

#include <writable_matcher.h>

class TextAnimator : public QObject {
  Q_OBJECT
 public:
  explicit TextAnimator(QObject* parent = nullptr,
                        unsigned int animation_delay = 10);
  ~TextAnimator();

  void SetAnimationDelay(unsigned int animation_delay);
  void SetAnimationText(const QString& animation_text);

  template <typename T>
  void RunAnimation(T* widget);

 private slots:
  void AnimateText();

  void Sleep() {}

 private:
  void Reset();
  bool IsStringEnd() const;

  QTimer* timer_ = nullptr;
  QString animation_text_;
  QString current_text_;
  unsigned int animation_delay_;
  unsigned int symbol_count_ = 0;

  class BaseWritableWidget {
   public:
    virtual ~BaseWritableWidget() {}
    virtual void SetText(const QString& text) = 0;
  };

  template <class U>
  class QtWritableWidget : public BaseWritableWidget {
   public:
    QtWritableWidget(U* qt_writable_widget)
        : qt_writable_widget_(qt_writable_widget) {}
    ~QtWritableWidget() {}

    void SetText(const QString& text) { qt_writable_widget_->setText(text); }

   private:
    U* qt_writable_widget_ = nullptr;
  };

  BaseWritableWidget* writable_widget_ = nullptr;
};

template <typename T>
void TextAnimator::RunAnimation(T* widget) {
  if (WritableMatcher::IsWidgetWritable(widget->metaObject()->className())) {
    writable_widget_ = new QtWritableWidget<T>(widget);
    timer_->start(animation_delay_);

  } else {
    throw std::logic_error(
        "incompatible type for text animation, add type to "
        "WritableMatcher class");
  }
}
#endif  // TEXT_ANIMATOR_H
