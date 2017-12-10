#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <QApplication>

int main(int argc, char** argv) {
  doctest::Context context;
  QApplication app(argc, argv);
  context.applyCommandLine(argc, argv);
  int result_of_tests = context.run();

  return result_of_tests;
}
