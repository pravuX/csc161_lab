#include <iostream>
using namespace std;

int x=5, y=15; // global variables
int &setx();

int main() {
    setx() = y; // identifier returned by setx is reference to y
    cout << "x = " << x << endl;;  // 15, value of y since x is an alias for y
    return 0;
}

int &setx() {
    cout << "x = " << x << endl;;  // 5
    return x;
}
