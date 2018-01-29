#include <test_message.h>

#include <QDebug>

using namespace demo_code;

unsigned int TestMessage::kCount = 0;

void TestMessage::WriteTestMessage(const QString& what_you_test_description) {
  qDebug() << "#" << kCount << what_you_test_description;
  ++kCount;
}
