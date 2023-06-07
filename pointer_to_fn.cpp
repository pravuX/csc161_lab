#include <iostream>
using namespace std;

int square(int n) {
    return n * n;
}


int main() {
    int n;
    int (*fptr)(int n);
    fptr = square;
    cout << "Enter number to find square:" << endl;
    cin >> n;
    cout << n << "^2 = " << fptr(n) << endl;
    return 0;
}
