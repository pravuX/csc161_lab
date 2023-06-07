#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int *arr, n, i, sum;
    cout << "Enter the number of integers:" << endl;
    cin >> n;
    arr = new (nothrow) int[n];
    if (arr == nullptr) {
        cout << "Error: Memory allocation failed!";
        return 1;
    }
    cout << "Enter the integers:" << endl;
    for (i = 0, sum = 0; i < n; i++) {
        cin >> *(arr + i); // arr[i]
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
    delete[] arr;
    return 0;
}
