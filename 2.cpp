#include <iostream>

using namespace std;

inline float area(float rad) { return 22.0 / 7 * rad * rad; }

int main(int argc, char *argv[]) {
  float radius, a;
  cout << "Enter Radius of Circle: ";
  cin >> radius;
  a = area(radius);
  cout << "Area = " << a << endl;
  return 0;
}
