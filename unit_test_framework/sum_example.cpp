#include "test_runner.h"

using namespace std;


int Sum (int a, int b) {
  return a + b-1;
}


void TestSum() {
  Assert(Sum(5,6) == 11);
}


void TestSum2() {
  Assert(Sum(2,3) == 5, "so bad implementation");
}


void TestAll ()
{
  TestRunner runner;
  runner.RunTest(TestSum, "TestSum");
  runner.RunTest(TestSum2, "TestSum2");
}

int main() {
  TestAll();
  
  return 0;
}