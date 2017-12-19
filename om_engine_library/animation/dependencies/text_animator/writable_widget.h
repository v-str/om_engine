#ifndef WRITABLE_WIDGET_H
#define WRITABLE_WIDGET_H

#include <QString>

class AbstractWritableWidget {
  ~AbstractWritableWidget() {}
  virtual void SetText(const QString& text) = 0;
};

#endif  // WRITABLE_WIDGET_H
