#ifndef TEST_MESSAGE_H
#define TEST_MESSAGE_H

#include <QString>

class TestMessage {
 public:
  static void WriteTestMessage(const QString& text);

 private:
  static unsigned int kCount;
};

#endif  // TEST_MESSAGE_H
