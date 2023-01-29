#include <iostream>

using namespace std;

template <class T>
T myMax(T x, T y) {
  return x > y ? x : y;
}

int main() {
  cout << myMax<float>(2.2, 5.5);
  return 0;
}
