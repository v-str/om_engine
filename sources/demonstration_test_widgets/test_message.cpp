#include <test_message.h>

#include <QDebug>

unsigned int TestMessage::kCount = 0;

void TestMessage::WriteTestMessage(const QString& text) {
  qDebug() << kCount << ") " << text;
  ++kCount;
}
