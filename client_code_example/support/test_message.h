#ifndef TEST_MESSAGE_H
#define TEST_MESSAGE_H

#include <QString>

namespace demo_code {

class TestMessage {
 public:
  static void WriteTestMessage(const QString& what_you_test_description);

 private:
  static unsigned int kCount;
};
}

#endif  // TEST_MESSAGE_H
