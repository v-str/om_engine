#ifndef WRITABLE_WIDGET_H
#define WRITABLE_WIDGET_H

#include <QString>

namespace om_animation {
class AbstractWritableWidget {
 public:
  ~AbstractWritableWidget() {}
  virtual void SetText(const QString& text) = 0;
};

template <class Widget>
class WritableWidget : public AbstractWritableWidget {
 public:
  WritableWidget(Widget* writable_widget) : writable_widget_(writable_widget) {}
  ~WritableWidget() {}

  void SetText(const QString& text) override {
    writable_widget_->setText(text);
  }

 private:
  Widget* writable_widget_ = nullptr;
};
}

#endif  // WRITABLE_WIDGET_H
