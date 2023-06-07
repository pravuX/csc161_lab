#include <iostream>

using namespace std;

class Test {
  int a;

public:
  Test() { a = 0; }
  void show() { cout << "a = " << a << endl; }
};

int main() {
  Test *ptr = new Test;

  return 0;
}
